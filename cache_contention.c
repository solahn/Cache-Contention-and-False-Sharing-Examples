#define _GNU_SOURCE  // GNU 확장 기능 사용을 위한 매크로 정의

#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <time.h>
#include <sched.h>    // 스레드 어피니티 설정을 위한 헤더 파일
#include <unistd.h>

#define R_W_CYCLES 4000000
#define NUM_ITERATIONS 100

typedef struct {
    // // with Padding
    // volatile uint64_t readVal __attribute__((aligned(64)));
    // volatile uint64_t writeVal __attribute__((aligned(64)));

    // withdout Padding
    volatile uint64_t readVal;
    volatile uint64_t writeVal;

} CacheContention;

/* 읽기 스레드 함수 */
void* readThreadFtn(void* arg)
{
    CacheContention* cContention = (CacheContention*)arg;

    // 스레드 어피니티 설정: CPU 0에 고정
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    for (int i = 0; i < R_W_CYCLES; ++i)
    {
        (void)cContention->readVal; // readVal에 접근
    }
    return NULL;
}

/* 쓰기 스레드 함수 */
void* writeThreadFtn(void* arg)
{
    CacheContention* cContention = (CacheContention*)arg;

    // 스레드 어피니티 설정: CPU 1에 고정
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    for (int i = 0; i < R_W_CYCLES; ++i)
    {
        cContention->writeVal = i; // writeVal에 값 쓰기
    }
    return NULL;
}

int main()
{
    double total_time = 0.0;
    CacheContention cc;

    for (int i = 0; i < NUM_ITERATIONS; ++i)
    {
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start); // 타이머 시작

        pthread_t readThread, writeThread;
        pthread_create(&readThread, NULL, readThreadFtn, &cc);
        pthread_create(&writeThread, NULL, writeThreadFtn, &cc);
        pthread_join(readThread, NULL);
        pthread_join(writeThread, NULL);

        clock_gettime(CLOCK_MONOTONIC, &end); // 타이머 종료

        double elapsed_seconds = (end.tv_sec - start.tv_sec) +
                                 (end.tv_nsec - start.tv_nsec) / 1e9;
        total_time += elapsed_seconds;
    }

    double average_time = total_time / NUM_ITERATIONS;
    printf("평균 실행 시간: %f 초\n", average_time);

    return 0;
}

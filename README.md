# Cache Contention and False Sharing Demo

캐시 경합(Cache Contention)과 거짓 공유(False Sharing)를 보여주는 예제 코드입니다. 이 레포지토리는 멀티스레드 프로그래밍에서 발생할 수 있는 성능 저하 이슈를 이해하고, 이를 완화하는 방법을 실험하기 위한 C 언어 프로그램을 제공합니다.

이 글은 다음의 원본 글을 기반으로 작성되었습니다:

https://www.linkedin.com/pulse/understanding-mitigating-cache-contention-false-sharing-ijaz-ahmad-uwbzf/

또한, 블로그 포스트에서 전문을 확인하실 수 있습니다:

https://solan.tistory.com/34

## 요구 사항

- Ubuntu 18.04 이상 또는 기타 리눅스 배포판
- GCC 컴파일러 (GNU Compiler Collection)
- `pthread` 라이브러리

## 설치

필수 패키지를 설치합니다:

```bash
sudo apt update
sudo apt install build-essential
```

## 실행 방법
```bash
# 코드 복제
git clone https://github.com/YourUsername/CacheContentionAndFalseSharingDemo.git
cd CacheContentionAndFalseSharingDemo

# 코드 컴파일
gcc cache_contention.c -o cache_contention -pthread

# 프로그램 실행
./cache_contention
```

이 예제를 통해 캐시 경합과 거짓 공유가 프로그램 성능에 어떤 영향을 미치는지 확인하고, 데이터 구조의 메모리 배치를 최적화하여 성능을 향상시키는 방법을 학습할 수 있습니다.

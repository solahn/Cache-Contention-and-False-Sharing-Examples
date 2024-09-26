# Cache Contention and False Sharing Demo

캐시 경합(Cache Contention)과 거짓 공유(False Sharing)를 보여주는 예제 코드입니다. 이 레포지토리는 멀티스레드 프로그래밍에서 발생할 수 있는 성능 저하 이슈를 이해하고, 이를 완화하는 방법을 실험하기 위한 C 언어 프로그램을 제공합니다.

## 소개

- **캐시 경합(Cache Contention)**: 여러 스레드가 동일한 캐시 라인에 접근하여 지연 시간과 동기화 오버헤드가 증가하는 현상입니다.
- **거짓 공유(False Sharing)**: 스레드들이 다른 변수를 사용하지만, 이 변수들이 동일한 캐시 라인에 위치하여 불필요한 캐시 동기화가 발생하는 현상입니다.

이 예제 코드를 통해 캐시 경합과 거짓 공유가 프로그램 성능에 어떤 영향을 미치는지 확인하고, 데이터 구조의 메모리 배치를 최적화하여 성능을 향상시키는 방법을 학습할 수 있습니다.

## 요구 사항

- **운영체제**: Ubuntu 18.04 이상 또는 기타 리눅스 배포판
- **컴파일러**: GCC (GNU Compiler Collection)
- **필수 패키지**:
  - `build-essential` (GCC 및 기타 빌드 도구)
  - `pthread` 라이브러리
  - `cpufrequtils` (선택 사항, CPU 주파수 설정용)
  - `sysstat` (선택 사항, 성능 모니터링 도구)

## 설치

### 필수 패키지 설치

```bash
sudo apt update
sudo apt install build-essential

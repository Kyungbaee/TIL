#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 0 << "\n";
        return 0;
    }

    // 1단계: 에라토스테네스의 체를 이용한 소수 생성
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // N 이하의 소수들을 벡터에 저장
    std::vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // 2단계: 투 포인터 알고리즘을 이용한 연속합 탐색
    int count = 0;
    int start = 0;
    int end = 0;
    long long current_sum = 0;
    int prime_count = primes.size();

    while (true) {
        if (current_sum >= N) {
            // 합이 N보다 크거나 같으면, start 포인터를 이동시켜 합을 줄임
            current_sum -= primes[start++];
        } else if (end == prime_count) {
            // end가 끝에 도달했고, 합이 N보다 작으면 더 이상 진행 불가
            break;
        } else {
            // 합이 N보다 작으면, end 포인터를 이동시켜 합을 늘림
            current_sum += primes[end++];
        }

        if (current_sum == N) {
            count++;
        }
    }

    std::cout << count << "\n";

    return 0;
}
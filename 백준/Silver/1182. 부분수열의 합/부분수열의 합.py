from sys import stdin
from itertools import combinations

if __name__ == "__main__":
    N, S = map(int, stdin.readline().split())
    num_list = list(map(int,stdin.readline().split()))

    answer = 0
    for cnt in range(1,N+1):
        for numbers in combinations(num_list,cnt):
            if sum(numbers) == S:
                answer += 1

    print(answer)
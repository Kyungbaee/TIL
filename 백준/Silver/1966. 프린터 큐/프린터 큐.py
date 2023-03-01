from sys import stdin
from collections import deque

if __name__ == "__main__":
    T = int(stdin.readline())

    for _ in range(T):
        N, M = map(int, stdin.readline().split())
        num_q = deque(map(int, stdin.readline().split()))
        cnt, idx = 0, 0
        while(len(num_q)!=0):
            print_item = num_q.popleft()
            check = 0
            for compare in num_q:
                if print_item < compare:
                    check = 1
                    break

            if check:
                num_q.append(print_item)
                if M == 0:
                    M = len(num_q)
            else:
                cnt += 1
                if M == 0:
                    print(cnt)
                    break
            M -= 1
            idx += 1
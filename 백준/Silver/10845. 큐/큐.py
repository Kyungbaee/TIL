from sys import stdin
from collections import deque

if __name__ == "__main__":
    N = int(stdin.readline())

    num_q = deque()
    for _ in range(N):
        for command in list(stdin.readline().split()):
            if str.isdigit(command):
                num_q.append(command)
            if command == "pop":
                if len(num_q):
                    print(num_q.popleft())
                else:
                    print(-1)
            if command == "size":
                print(len(num_q))
            if command == "empty":
                if len(num_q):
                    print(0)
                else:
                    print(1)
            if command == "front":
                if len(num_q):
                    print(num_q[0])
                else:
                    print(-1)
            if command == "back":
                if len(num_q):
                    print(num_q[-1])
                else:
                    print(-1)
from sys import stdin
from collections import deque

if __name__ == "__main__":
    N = int(stdin.readline())

    num_list = deque(sorted(list(map(int, stdin.readline().split()))))

    if N == 1:
        num = num_list.pop()
        print(num*num)
    if N > 1:
        l_num = num_list.popleft()
        r_num = num_list.pop()
        print(l_num*r_num)
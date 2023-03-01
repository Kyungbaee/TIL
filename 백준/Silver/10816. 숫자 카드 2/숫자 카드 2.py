from sys import stdin
from collections import defaultdict

if __name__ == "__main__":
    num_dict = defaultdict(int)
    N = int(stdin.readline())
    A, B = [],[]
    for a in list(stdin.readline().split()):
        A.append(int(a))
        num_dict[int(a)] += 1
    M = int(stdin.readline())
    for b in list(stdin.readline().split()):
        B.append(int(b))

    print(*[num_dict[num] for num in B])
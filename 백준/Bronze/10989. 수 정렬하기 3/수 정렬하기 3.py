from sys import stdin
import heapq
from collections import defaultdict

if __name__ == "__main__":
    N = int(stdin.readline())
    num_q = []
    num_cnt = defaultdict(int)

    for _ in range(N):
        num = int(stdin.readline())
        if num_cnt[num] == 0:
            heapq.heappush(num_q, num)
        num_cnt[num] += 1
    
    while(len(num_q) != 0):
        repeat = heapq.heappop(num_q)
        for _ in range(num_cnt[repeat]):
            print(repeat)
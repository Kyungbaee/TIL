from sys import stdin
import heapq

if __name__ == "__main__":
    N = int(stdin.readline())
    num_q = []

    for _ in range(N):
        heapq.heappush(num_q, int(stdin.readline()))
    
    while(len(num_q) != 0):
        print(heapq.heappop(num_q))
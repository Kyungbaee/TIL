from sys import stdin
import heapq

if __name__ == "__main__":
    N,K = map(int, stdin.readline().split())
    answer = 0
    mv_list = []
    for _ in range(N):
        M,V = map(int, stdin.readline().split())
        mv_list.append([M,V])
    
    c_queue = []
    for _ in range(K):
        heapq.heappush(c_queue, int(stdin.readline()))

    mv_list = sorted(mv_list, key=lambda item : item[0])

    idx = 0
    item_queue = []
    while(len(c_queue) != 0):
        C = heapq.heappop(c_queue)
        while(idx < N and C >= mv_list[idx][0]):
            heapq.heappush(item_queue, -mv_list[idx][1])
            idx += 1
        if item_queue:
            answer += -heapq.heappop(item_queue)
    print(answer)
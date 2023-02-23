from sys import stdin
import heapq

if __name__ == "__main__":
	# 보석, 가방의 수
    N,K = map(int, stdin.readline().split())
    answer = 0
    
    # 무게와 가치를 담는 리스트
    mv_list = []
    for _ in range(N):
        M,V = map(int, stdin.readline().split())
        mv_list.append([M,V])
    
    # 가방을 크기 오름차순으로 넣기
    c_queue = []
    for _ in range(K):
        heapq.heappush(c_queue, int(stdin.readline()))

	# 보석 무게 순으로 정렬
    mv_list = sorted(mv_list, key=lambda item : item[0])

    idx = 0
    item_queue = []
    while(len(c_queue) != 0):
        C = heapq.heappop(c_queue)
        # 가방에 들어갈 무게인 보석을 가치 내림차순으로 넣기
        while(idx < N and C >= mv_list[idx][0]):
            heapq.heappush(item_queue, -mv_list[idx][1])
            idx += 1
        # 가장 가치가 높은 보석 빼기
        if item_queue:
            answer += -heapq.heappop(item_queue)
    print(answer)

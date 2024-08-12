import heapq as hq

def solution(scoville, K):
    answer = 0
    hq.heapify(scoville)
    
    while(len(scoville)>1):
        if scoville[0]>=K: break
        answer += 1
        hq.heappush(scoville, hq.heappop(scoville)+hq.heappop(scoville)*2)

    if len(scoville)==1 and scoville[0]<K: return -1
    return answer
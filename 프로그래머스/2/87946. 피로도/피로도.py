from itertools import permutations
def solution(k, dungeons):
    answer = 0
    ## 던전을 탐험하는 경우의 수 탐색
    for p in permutations(dungeons, len(dungeons)):
        energy, complete = k, 0
        
        for act in p:
            ## 피로도가 탐험 가능한 상태라면, 피로도 소모
            ## 완료한 탐험 +1
            if energy >= act[0]:
                energy -= act[1]
                complete += 1
        answer = max(complete, answer)
    return answer
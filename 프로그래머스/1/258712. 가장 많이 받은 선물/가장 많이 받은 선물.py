from collections import defaultdict
def solution(friends, gifts):
    answer = defaultdict(int)
    send, receive, p_score = defaultdict(list), defaultdict(list), defaultdict(int)
    
    for g in gifts:
        s, r = g.split(" ")
        send[s].append(r)
        receive[r].append(s)
    
    for f in friends: p_score[f] = len(send[f])-len(receive[f])
        
    for i in range(len(friends)):
        for j in friends[i+1:]:
            if send[friends[i]].count(j) > send[j].count(friends[i]): answer[friends[i]] += 1
            elif send[friends[i]].count(j) < send[j].count(friends[i]): answer[j] += 1
            elif p_score[friends[i]] > p_score[j]: answer[friends[i]] += 1
            elif p_score[friends[i]] < p_score[j]: answer[j] += 1
    
    answer = answer.values()
    if answer: return max(answer)
    return 0
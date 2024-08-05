from collections import defaultdict
def solution(participant, completion):
    p_map = defaultdict(int)
    for p_key in participant: p_map[p_key] += 1
    for c_key in completion : p_map[c_key] -= 1
    return sorted(p_map.items(), key=lambda x:x[1], reverse=True)[0][0]
    
    
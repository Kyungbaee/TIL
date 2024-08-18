from collections import defaultdict
def solution(n, lost, reserve):
    d = defaultdict(int)
    lost, reserve = sorted(lost), sorted(reserve)
    
    for i in range(1,n+1):
        if (i in reserve) and (i in lost): d[i] = 1
        elif i in reserve: d[i] = 2
        elif i in lost: d[i] = 0
        else: d[i] = 1

    for i in lost:
        if d[i-1] > 1: 
            d[i-1] -= 1
            d[i] = 1
            continue
            
        if i < n and d[i+1] > 1:
            d[i+1] -= 1
            d[i] = 1
            
    return len(list(filter(lambda x: x[1]>0, d.items())))
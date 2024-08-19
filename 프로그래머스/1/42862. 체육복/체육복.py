from collections import defaultdict
def solution(n, lost, reserve):
    ## 체육복이 없는 학생은 수업에 들을 수 없음.
    ## 앞 번호, 뒷 번호 학생에게만 빌려줄 수 있음.
    d = defaultdict(int)
    lost, reserve = sorted(lost), sorted(reserve)
    
    ## 여분의 체육복이 있는 학생 : 2
    ## 여분이 있으나 체육복을 잃어버린 학생 : 1
    ## 본인 체육복만 있는 학생 : 1
    ## 체육복을 잃어버린 학생 : 0
    for i in range(1,n+1):
        if (i in reserve) and (i in lost): d[i] = 1
        elif i in reserve: d[i] = 2
        elif i in lost: d[i] = 0
        else: d[i] = 1

    for i in lost:
        ## 앞 번호 학생에게 체육복을 빌림.
        if d[i-1] > 1: 
            d[i-1] -= 1
            d[i] = 1
            continue
        
        ## 뒷 번호 학생에게 체육복을 빌림.
        if i < n and d[i+1] > 1:
            d[i+1] -= 1
            d[i] = 1
    
    ## 체육복이 있는 학생 수 반환
    return len(list(filter(lambda x: x[1]>0, d.items())))
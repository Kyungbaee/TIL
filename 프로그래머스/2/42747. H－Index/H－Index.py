def solution(citations):
    citations, n, answer = sorted(citations, reverse=True), len(citations), 0
    for hh in range(n,-1,-1):
        cnt = 0
        for idx in range(n):
            if (citations[idx] < hh): break
            else: cnt += 1
    
        if (cnt >= hh) and (n-cnt <= hh): return hh
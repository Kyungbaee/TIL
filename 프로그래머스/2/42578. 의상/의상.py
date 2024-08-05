from collections import Counter
from functools import reduce

def solution(clothes):
        
    clo = [clothe[1] for clothe in clothes]
    answer = len(clo)
    cnt = Counter(clo).values()
    cnt = list(map(lambda x : x+1, cnt))
    answer = reduce(lambda x, y: x * y, cnt) - 1

    return answer
from collections import defaultdict
def solution(name, yearning, photo):
    answer, d = [], defaultdict(int)
    for idx, n in enumerate(name): d[n]=yearning[idx]
    for p in photo: answer.append(sum([d[pp] for pp in p]))
    return answer
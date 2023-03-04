from sys import stdin
from itertools import combinations

if __name__ == "__main__":
    N = int(stdin.readline())
    num_map, num_set, answer = [], set(), float('inf')

    for idx in range(1,N+1):
        num_map.append(list(map(int,stdin.readline().split())))
        num_set.add(idx)

    com_list = list(combinations(num_set,N//2))

    for idx in range(len(com_list)//2):
        start_score = 0
        for s in combinations(com_list[idx],2):
            start_score += num_map[s[0]-1][s[1]-1] + num_map[s[1]-1][s[0]-1]
        
        link_score = 0
        for l in combinations(num_set-set(com_list[idx]),2):
            link_score += num_map[l[0]-1][l[1]-1] + num_map[l[1]-1][l[0]-1]

        min_gap = abs(start_score - link_score)
        if min_gap < answer:
            answer = min_gap
        if answer == 0:
            break
    
    print(answer)
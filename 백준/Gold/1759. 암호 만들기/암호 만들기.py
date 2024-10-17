from itertools import combinations

L, C = map(int, input().split())
c_list = sorted(input().split())

for c in combinations(c_list, L):
    spell_cnt = 0
    for a in c:
        if a in ('a','e','i','o','u'): spell_cnt += 1
        
    if spell_cnt>=1 and (L-spell_cnt)>=2:
        print(''.join(c))
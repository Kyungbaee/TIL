from collections import defaultdict

s = input()
ans, d = [], defaultdict(int)

for ss in s:
    ss = ss.upper()
    d[ss] += 1

max_v = max(d.values())

for chr, cnt in d.items():
    if cnt == max_v: ans.append(chr)

if len(ans)==1: print(ans[0])
else: print("?")
v = [-1]*11
N = int(input())
cnt = 0

for _ in range(N):
    cow, loc = map(int, input().split())
    if v[cow] == 0 and loc == 1:
        v[cow] = loc
        cnt += 1
    elif v[cow] == 1 and loc == 0:
        v[cow] = loc
        cnt += 1
    else:
        v[cow] = loc
print(cnt)
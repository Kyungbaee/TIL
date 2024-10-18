import sys
input = sys.stdin.readline

N = int(input())
s = [list(map(int,input().split())) for _ in range(N)]
m = [0]*(N+1)

money = 0
for i in range(N):
    money = max(money, m[i])

    if i+s[i][0]>N: continue

    m[i+s[i][0]] = max(money+s[i][1], m[i+s[i][0]])
print(max(m))
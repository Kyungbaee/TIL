N, M = map(int, input().split())
art = [list(input()) for _ in range(N)]
v = [[0]*M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if art[i][j] != '.' and v[i][j]==0:
            art[i][-1-j] = art[i][j]
            v[i][j] = 1
            v[i][-1-j] = 1

for i in range(N):
    print(''.join(art[i]))
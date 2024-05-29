N = int(input())
M = [list(map(int, input().split())) for _ in range(N)]
dp = [[0]*N for _ in range(N)]
dp[0][0] = 1

for i in range(N):
    for j in range(N):
        if i==N-1 and j==N-1:
            break
        if dp[i][j]:
            for di, dj in ((M[i][j],0), (0,M[i][j])):
                ni, nj = i+di, j+dj
                if 0<= ni < N and 0<= nj <N:
                    dp[ni][nj] += dp[i][j]
print(dp[N-1][N-1])
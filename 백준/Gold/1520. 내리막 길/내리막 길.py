def dfs(m,n):
    if dp[m][n] == -1:
        dp[m][n] = 0
        for di, dj in ((1,0), (0,1), (-1,0), (0,-1)):
            pi, pj = m+di, n+dj
            if m_list[pi][pj] > m_list[m][n]:
                dp[m][n] += dfs(pi, pj)
    return dp[m][n]

M, N = map(int, input().split())
m_list = [[0]*(N+2)]+[[0]+list(map(int, input().split()))+[0] for _ in range(M)]+[[0]*(N+2)]
dp = [[-1]*(N+2) for _ in range(M+2)]
dp[1][1] = 1

print(dfs(M,N))
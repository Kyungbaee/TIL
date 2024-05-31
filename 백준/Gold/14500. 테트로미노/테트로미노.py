from collections import deque
def dfs(si, sj, v, cnt):
    global ans
    if len(cnt)==4:
        ans = max(ans, sum(cnt))
        return ans

    for di, dj in ((0,1), (1,0), (-1,0), (0,-1)):
        ni, nj = si+di, sj+dj
        if 0<= ni <N and 0<= nj <M and v[ni][nj]==0:
            v[ni][nj]=1
            cnt.append(m_list[ni][nj])
            dfs(ni,nj,v,cnt)
            v[ni][nj]=0
            cnt.pop()


N, M = map(int, input().split())
m_list = [list(map(int, input().split())) for _ in range(N)]
v = [[0]*M for _ in range(N)]
ans, cnt = 0, deque()

for i in range(N):
    for j in range(M):
        v[i][j]=1
        cnt.append(m_list[i][j])
        dfs(i,j,v,cnt)
        v[i][j]=0
        cnt.pop()

        if 0<i and 0<j<M-1:
            ans = max(ans, m_list[i-1][j]+sum(m_list[i][j-1:j+2]))
        if 0<i<N-1 and j<M-1:
            ans = max(ans, m_list[i][j+1]+m_list[i-1][j]+m_list[i][j]+m_list[i+1][j])
        if i<N-1 and 0<j<M-1:
            ans = max(ans, sum(m_list[i][j-1:j+2])+m_list[i+1][j])
        if 0<i<N-1 and 0<j:
            ans = max(ans, m_list[i][j-1]+m_list[i-1][j]+m_list[i][j]+m_list[i+1][j])
print(ans)
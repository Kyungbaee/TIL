from collections import deque
def bfs(w):
    cnt = 0
    q = deque()
    v = [[0]*N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if adj[i][j] > w and v[i][j]==0:
                q.append((i,j))
                v[i][j]=1

                while q:
                    cx, cy = q.popleft()
                    if v[cx][cy] == 1:
                        cnt += 1

                    for dx, dy in ((0,1), (1,0),(-1,0),(0,-1)):
                        nx, ny = cx+dx, cy+dy
                        if 0<=nx<N and 0<=ny<N and adj[nx][ny] > w and v[nx][ny]==0:
                            q.append((nx,ny))
                            v[nx][ny] = v[cx][cy]+1
    return cnt

N = int(input())
adj = [list(map(int,input().split())) for _ in range(N)]
ans = 0

for h in range(0,101):
    ans = max(ans, bfs(h))
print(ans)
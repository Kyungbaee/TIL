from collections import deque
import copy
def bfs():
    cnt = 0
    q = deque()
    v = [[0]*M for _ in range(N)]
    c_list = copy.deepcopy(adj)

    for i in range(1,N-1):
        for j in range(1,M-1):
            if adj[i][j] != 0 and v[i][j]==0:
                q.append((i,j))
                v[i][j]=1

            while q:
                cx, cy = q.popleft()
                if v[cx][cy]==1:
                    cnt += 1

                for dx, dy in ((0,1), (1,0), (0,-1),(-1,0)):
                    nx, ny = cx+dx, cy+dy
                    if 1<=nx<N-1 and 1<=ny<M-1 and adj[nx][ny]!=0 and v[nx][ny]==0:
                        q.append((nx,ny))
                        v[nx][ny] = v[cx][cy]+1
                    if 0<=nx<N and 0<=ny<M and adj[nx][ny]==0 and c_list[cx][cy]>0:
                        c_list[cx][cy] -= 1
    if cnt>1:
        return 0
    return c_list

N, M = map(int, input().split())
adj = [list(map(int, input().split())) for _ in range(N)]
ans = 1
while ans:
    cnt = bfs()
    if cnt:
        adj = copy.deepcopy(cnt)
        ans += 1
    elif not cnt:
        print(ans-1)
        break
    if sum(sum(i)for i in adj) == 0:
        print(0)
        break
from collections import deque
def bfs(si, sj, c_list,v):
    q = deque()
    q.append((si,sj))
    v[si][sj]=1
    c_list[si][sj]=0

    while q:
        si, sj = q.popleft()

        for di, dj in ((0,1),(1,0),(0,-1),(-1,0)):
            ni, nj = si+di, sj+dj
            if 0<=ni<N and 0<=nj<M and v[ni][nj]==0 and m_list[ni][nj]==0:
                v[ni][nj]=1
                c_list[ni][nj]=0
                q.append((ni,nj))
    return c_list,v

def solve():
    c_list = [[-1]*M for _ in range(N)]
    v = [[0]*M for _ in range(N)]
    c_list,v = bfs(0,0,c_list,v)

    for i in range(N):
        for j in range(M):
            if m_list[i][j]:
                c_list[i][j]=1
                for dx,dy in ((0,1),(1,0),(0,-1),(-1,0)):
                    nx,ny = i+dx,j+dy
                    if 0<=nx<N and 0<=ny<M and m_list[nx][ny]==0 and c_list[nx][ny]==0:
                        c_list[i][j]=0
                        break

    for i in range(N):
        for j in range(M):
            if c_list[i][j]==-1:
                c_list[i][j]=0

    return c_list

N, M = map(int, input().split())
m_list = [list(map(int,input().split())) for _ in range(N)]
clear_time, last_c = 0, sum([sum(m_list[i]) for i in range(N)])

while True:
    m_list = solve()
    clear_time += 1

    cnt = sum([sum(m_list[i]) for i in range(N)])
    if not cnt:
        break
    elif cnt:
        last_c = cnt
print(clear_time)
print(last_c)
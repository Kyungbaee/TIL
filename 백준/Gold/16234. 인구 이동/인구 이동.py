from collections import deque

N, L, R = map(int, input().split())
m_list = []

for _ in range(N):
    m_list.append(list(map(int, input().split())))

ans = 0
q = deque()

while ans <= 2000:
    flag = 0
    v = [[0]*N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if v[i][j] == 0:
                q.append((i,j))
                v[i][j] = 1
                team = [(i,j)]
                sm = m_list[i][j]

                while q:
                    ci, cj = q.popleft()
                    for si, sj in [(-1,0), (1,0), (0,-1), (0,1)]:
                        ni, nj = ci+si, cj+sj
                        if 0<=ni<N and 0<=nj<N and L<=abs(m_list[ci][cj] - m_list[ni][nj])<=R and v[ni][nj] == 0:
                            q.append((ni,nj))
                            v[ni][nj]=1
                            team.append((ni,nj))
                            sm += m_list[ni][nj]

                if len(team) > 1:
                    for ti, tj in team:
                        m_list[ti][tj] = sm // len(team)
                    flag = 1

    if flag == 0:
        break
    ans += 1

print(ans)
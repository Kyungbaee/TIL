N, M = map(int,input().split())
m_list = [list(map(int,input().split())) for _ in range(N)]
v_list = [[0]*M for _ in range(N)]

for x in range(1,N-1):
    for y in range(1,M-1):

        for dx, dy in ((0,1), (1,0), (0,-1), (-1,0)):
            nx, ny = x+dx, y+dy
            if m_list[nx][ny] > m_list[x][y]:
                v_list[x][y]=1
            else:
                v_list[x][y]=0
                break

for v in v_list:
    print(*v)
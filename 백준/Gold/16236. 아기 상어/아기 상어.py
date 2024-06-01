from collections import deque
def bfs(si,sj,ei,ej,size):
    v = [[0]*N for _ in range(N)]
    q = deque()
    q.append((si, sj))
    v[si][sj]=1

    while q:
        ni, nj = q.popleft()
        if ni==ei and nj==ej:
            return v[ni][nj]-1

        for di, dj in ((0,1), (1,0), (-1,0), (0,-1)):
            mi, mj = ni+di, nj+dj
            if 0<=mi<N and 0<=mj<N and m_list[mi][mj]<=size and v[mi][mj]==0:
                q.append((mi,mj))
                v[mi][mj] = v[ni][nj]+1


def searh_fish(si,sj,size):
    # 먹을 물고기 리스트 순서대로
    e_list = [deque() for _ in range(21 * 21)]
    for x in range(N):
        for y in range(N):
            s = m_list[x][y]
            if 1<=s<=6 and s < size:
                cnt = bfs(si,sj,x,y,size)
                if cnt:
                    e_list[cnt].append((x,y))
                    sorted(e_list[cnt])
    return e_list

def solve(si, sj, size, cnt):
    # 먹을 물고기 리스트 순서대로 세팅
    s_list = searh_fish(si, sj, size)
    # 가까운 물고기부터 이동
    for time, st in enumerate(s_list):
        for x, y in st:
            si, sj = x, y
            m_list[x][y]=0
            cnt += 1
            return si, sj, size, cnt, time
    return 0,0,0,0,0

N = int(input())
m_list = [list(map(int, input().split())) for _ in range(N)]
si, sj, size, cnt = 0, 0, 2, 0

# 아기 상어 위치
for i in range(N):
    for j in range(N):
        if m_list[i][j]==9:
            si, sj = i, j
            m_list[i][j]=0

t=0
while True:
    si, sj, size, cnt, time = solve(si, sj, size, cnt)
    if size==0:
        break
    if size==cnt:
        cnt = 0
        size += 1
    t += time
print(t)
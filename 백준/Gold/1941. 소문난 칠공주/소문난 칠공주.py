from collections import deque

def bfs(m):
    visited = [[1]*5 for _ in range(5)]
    for mm in m:
        xx, yy = mm
        visited[xx][yy] = 0
    
    x, y = m[0]
    d = deque([(x,y)])
    visited[x][y]=1

    chk = 1

    while(d):
        vx, vy = d.popleft()

        for dx, dy in [[0,1],[1,0],[-1,0],[0,-1]]:
            mx, my = vx+dx, vy+dy

            if 0<=mx<5 and 0<=my<5 and not visited[mx][my]:
                d.append((mx,my))
                visited[mx][my]=1
                chk += 1
    
    if chk == 7:
        return True
    return False

def dfs(depth, start, count):
    global cnt

    if count >= 4:
        return
    
    if depth==7:
        if bfs(m_list): cnt += 1
        return
    
    for i in range(start, 25):
        x = i // 5
        y = i % 5

        m_list.append((x,y))
        dfs(depth+1, i+1, count + (member[x][y]=='Y'))
        m_list.pop()

    return


member = [[m for m in input()] for _ in range(5)]
ans_list, cnt = [], 0
m_list = []

dfs(0,0,0)
print(cnt)
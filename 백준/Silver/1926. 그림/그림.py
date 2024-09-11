from collections import deque
def solve(i, j):
    deq, width = deque([[i,j]]), 1
    visited[i][j] = 1

    while deq:
        x, y = deq.popleft()

        for dx, dy in [(0,1), (1,0), (0, -1), (-1, 0)]:
            nx, ny = x+dx, y+dy

            if 0<=nx<n and 0<=ny<m and not visited[nx][ny] and painting[nx][ny]:
                visited[nx][ny] = 1
                deq.append([nx, ny])
                width += 1

    return width

n, m = map(int, input().split())
painting = [list(map(int, input().split())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]
cnt_picture, max_width = 0, 0

for i in range(n):
    for j in range(m):
        if not visited[i][j] and painting[i][j]:
            cnt_picture += 1
            max_width = max(max_width, solve(i, j))

print(cnt_picture)
print(max_width)
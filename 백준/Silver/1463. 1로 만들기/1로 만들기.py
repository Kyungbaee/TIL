from sys import stdin
from collections import deque

def bfs(n):
    bfs_deque = deque([(n, 0)])

    while(len(bfs_deque) > 0):
        x, cnt = bfs_deque.popleft()

        if x == 1:
            return cnt

        if visited[x]:
            visited[x] = 0

            if (x%3 == 0) and visited[x//3]:
                bfs_deque.append((x//3, cnt+1))
            if (x%2 == 0) and visited[x//2]:
                bfs_deque.append((x//2, cnt+1))
            if (x > 1) and visited[x-1]:
                bfs_deque.append((x-1, cnt+1))

N = int(stdin.readline())
visited = [1]*(10**6+1)

print(bfs(N))
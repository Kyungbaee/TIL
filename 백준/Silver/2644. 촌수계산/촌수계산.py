def bfs(A,B):
    v[A] = 1
    q = []
    q.append(A)

    while q:
        n = q.pop(0)
        if n == B:
            return v[n]-1

        for i in adj[n]:
            if not v[i]:
                v[i] += v[n]+1
                q.append(i)
    return -1

N = int(input())
A,B = map(int, input().split())
M = int(input())
adj = [[] for _ in range(N+1)]

for c in range(M):
    x, y = map(int,input().split())
    adj[x].append(y)
    adj[y].append(x)

v = [0]*(N+1)
print(bfs(A,B))


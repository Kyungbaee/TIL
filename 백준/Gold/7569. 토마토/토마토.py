from collections import deque
def bfs(n, m, h):
    v, q, cnt = [], deque(), 0
    for _ in range(h):
        v.append([[0]*m for _ in range(n)])

    for nh in range(h):
        for nn in range(n):
            for nm in range(m):
                if adj[nh][nn][nm] == 1:
                    q.append([nm,nn,nh])
                    v[nh][nn][nm] = 1
                elif adj[nh][nn][nm] == 0:
                    cnt += 1

    if cnt == 0:
        return 0

    while q:
        cm, cn, ch = q.popleft()

        for dh, dn, dm in [(0,0,-1), (0,0,1), (0,1,0), (0,-1,0), (1,0,0),(-1,0,0)]:
            nh, nn, nm = ch+dh, cn+dn, cm+dm
            # 방향 검사
            if (0 <= nm < m) and (0 <= nn < n) and (0 <= nh < h) and (v[nh][nn][nm] == 0) and (adj[nh][nn][nm] == 0):
                q.append([nm, nn, nh])
                v[nh][nn][nm] = v[ch][cn][cm]+1
                cnt -= 1

    if cnt == 0 :
        return v[ch][cn][cm]-1
    else:
        return -1



M, N, H = map(int,input().split())

adj = []

for _ in range(H):
    t = []
    for _ in range(N):
        t.append(list(map(int,input().split())))
    adj.append((t))

print(bfs(N,M,H))
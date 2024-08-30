from collections import deque

def solution(maps):
    n, m = len(maps)-1, len(maps[0])-1
    move = [[-1,0], [0,-1], [1,0], [0,1]]
    deq = deque([[0,0]])
    maps[0][0] = -1
    
    while deq:
        vn, vm = deq.popleft()
        if vn==n and vm==m:
            return maps[n][m]*(-1)
        
        for mm in move:
            nn, nm = vn+mm[0], vm+mm[1]
            if (0<=nn<=n) and (0<=nm<=m) and (maps[nn][nm]==1):
                deq.append([nn,nm])
                maps[nn][nm] = maps[vn][vm]-1
    return -1
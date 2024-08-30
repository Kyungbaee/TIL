from collections import deque
'''
BFS
'''
def solution(maps):
    n, m = len(maps)-1, len(maps[0])-1
    move = [[-1,0], [0,-1], [1,0], [0,1]] ## 상,하,좌,우 이동
    deq = deque([[0,0]])
    maps[0][0] = -1
    
    while deq:
        vn, vm = deq.popleft()
        ## 도착한 경우
        if vn==n and vm==m:
            return maps[n][m]*(-1)
        
        ## 상,하,좌,우로 이동
        for mm in move:
            nn, nm = vn+mm[0], vm+mm[1]
            if (0<=nn<=n) and (0<=nm<=m) and (maps[nn][nm]==1):
                deq.append([nn,nm])
                maps[nn][nm] = maps[vn][vm]-1
    return -1
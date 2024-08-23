
"""
1 1 1 1
1 X 1 2
1 1 2 4
"""

def solution(m, n, puddles):
    mm = [[0]*m for i in range(n)]
    mm[0][0] = 1
    for p in puddles: mm[p[1]-1][p[0]-1] = -1
    
    for i in range(0,n):
        for j in range(0,m):
            if mm[i][j] == -1 or (i==0 and j==0):
                continue
            if mm[i-1][j] != -1: mm[i][j] += mm[i-1][j]
            if mm[i][j-1] != -1: mm[i][j] += mm[i][j-1]
            
    return mm[-1][-1]%1000000007
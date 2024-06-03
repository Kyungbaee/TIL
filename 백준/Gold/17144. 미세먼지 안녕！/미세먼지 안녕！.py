def solve(R,C):
    new_list = [[0] * C for _ in range(R)]
    air = []

    for i in range(R):
        for j in range(C):
            if m_list[i][j]>=5:
                D = m_list[i][j]//5
                new_list[i][j] += m_list[i][j]
                for di, dj in ((0,1),(1,0),(0,-1),(-1,0)):
                    ni, nj = i+di, j+dj

                    if 0<=ni<R and 0<=nj<C and m_list[ni][nj]>=0:
                        new_list[ni][nj] += D
                        new_list[i][j] -= D
            else:
                new_list[i][j] += m_list[i][j]
            if m_list[i][j] == -1:
                air.append((i,j))

    for idx, point in enumerate(air):
        x,y = point
        if not idx:
            new_list[x-1][y]=0
            for i in range(x-2,-1,-1):
                new_list[i+1][y] = new_list[i][y]
            for j in range(1,C):
                new_list[0][j-1] = new_list[0][j]
            for i in range(1,x+1):
                new_list[i-1][C-1] = new_list[i][C-1]
            for j in range(C-2,0,-1):
                new_list[x][j+1] = new_list[x][j]
            new_list[x][y+1]=0

        if idx:
            new_list[x+1][y]=0
            for i in range(x+2,R):
                new_list[i-1][y] = new_list[i][y]
            for j in range(1,C):
                new_list[R-1][j-1] = new_list[R-1][j]
            for i in range(R-2,x-1,-1):
                new_list[i+1][C-1] = new_list[i][C-1]
            for j in range(C-2,0,-1):
                new_list[x][j+1] = new_list[x][j]
            new_list[x][y+1]=0

    return new_list

R, C, T = map(int, input().split())
m_list = [list(map(int, input().split())) for _ in range(R)]

for _ in range(T):
    m_list = solve(R,C)
print(sum([sum(m) for m in m_list])+2)
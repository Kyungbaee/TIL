def check(x, y, z):
    for i in range(x,x+z):
        for j in range(y,y+z):
            if paper[i][j] != paper[x][y]:
                return False
    return True   

def cnt(x, y, n):
    if check(x, y, n):
        cnt_num[paper[x][y]+1] += 1
        return 

    z = n // 3
    for i in range(0,3):
        for j in range(0,3):
            cnt(x+i*z, y+j*z, z)
    return

N = int(input())
cnt_num = [0]*4
paper = [list(map(int, input().split())) for _ in range(N)]

cnt(0,0,N)

for p in cnt_num[:3]: print(p)
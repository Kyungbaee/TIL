def check(x,y,n):
    for i in range(x,x+n):
        for j in range(y,y+n):
            if num_map[i][j] != num_map[x][y]:
                return False
    return True

def solve(x,y,n):
    if check(x,y,n):
        cnt[num_map[x][y]] += 1
        return
    
    z = n // 2
    for i in range(2):
        for j in range(2):
            solve(x+i*z,y+j*z,z)

N = int(input())
num_map = [list(map(int, input().split())) for _ in range(N)]
cnt = [0]*2

solve(0,0,N)

for p in cnt: print(p)
def check(x,y,z):
    for i in range(x, x+z):
        for j in range(y, y+z):
            if num_map[i][j] != num_map[x][y]:
                return False
    return True

def solve(x,y,n):
    if check(x,y,n):
        ans_list.append(str(num_map[x][y]))
        return
    
    ans_list.append('(')
    z = n // 2
    for i in range(2):
        for j in range(2):
            solve(x+i*z, y+j*z, z)
    ans_list.append(')')

N = int(input())
num_map = [[int(t) for t in input()] for _ in range(N)]
ans_list = []

solve(0,0,N)

print(''.join(ans_list))
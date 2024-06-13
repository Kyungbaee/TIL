def solve(si, sj):
    global check, max_cnt
    max_cnt += 1
    c_list.append((si,sj))
    color = p_list[si][sj]

    for dx,dy in ((0,1),(1,0),(0,-1),(-1,0)):
        nx, ny = si+dx, sj+dy
        if 0<=nx<12 and 0<=ny<6 and p_list[nx][ny]==color and v[nx][ny]==0:
            v[nx][ny]=1
            solve(nx,ny)

    if max_cnt >= 4:
        return -1


def move():
    for si in range(12):
        for sj in range(6):
            if p_list[si][sj] != '.':
                cnt = 0
                i = si
                while 0<=i+1<12 and p_list[i+1][sj] == '.':
                    cnt += 1
                    i += 1

                c = 0
                while p_list[si-c][sj]!='.' and cnt>0 and si-c>=0:
                    p_list[si-c+cnt][sj] = p_list[si-c][sj]
                    p_list[si-c][sj]='.'
                    c += 1

p_list = [list(input()) for _ in range(12)]
ans, ans_check = 0, 1

while ans_check:
    v = [[0] * 6 for _ in range(12)]
    ans_check = 0
    for i in range(12):
        for j in range(6):
            if p_list[i][j] != '.' and v[i][j]==0:
                check, max_cnt, c_list = 0, 0, []
                v[i][j]=1
                solve(i,j)
                if c_list and max_cnt >= 4:
                    for c in c_list:
                        x,y = c
                        p_list[x][y] = '.'
                    move()
                    ans_check = 1
                    i, j = 0,0
    if ans_check:
        ans += 1
print(ans)
def solve():
    # 가로 체크
    for i in range(1, 4):
        check = sum(B[i])
        if check ==6 or check ==3:
            return check
    # 세로 체크
    for i in range(1, 4):
        check = B[1][i] + B[2][i] + B[3][i]
        if check ==6 or check ==3:
            return check
    # 대각선 체크
    check = B[1][1] + B[2][2] + B[3][3]
    if check == 6 or check == 3:
        return check
    check = B[1][3] + B[2][2] + B[3][1]
    if check == 6 or check == 3:
        return check
    return 0

S = int(input())
B = [[0]*4 for _ in range(4)]
for _ in range(9):
    x, y = map(int, input().split())
    if S==1:
        B[x][y]=1
        S+=1
    elif S==2:
        B[x][y]=2
        S-=1
ans = solve()
print(ans//3)
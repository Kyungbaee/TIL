N = int(input())
M = int(input())
car_list = [list(map(int,input().split())) for _ in range(N)]
ans = M

for c in car_list:
    plus, minus = c
    M = M+plus-minus

    if M < 0:
        ans = 0
        break
    else:
        ans = max(ans, M)
print(ans)
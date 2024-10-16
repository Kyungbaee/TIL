def solve(cnt, cur):
    if cnt == 6:
        print(*ans_list)
        return
    
    for i in range(cur, N[0]):
        ans_list[cnt] = n_list[i]
        solve(cnt+1, i+1)

while (True):
    N = list(map(int, input().split()))
    if N[0]==0: break
    n_list, ans_list = N[1:], [0]*6
    solve(0, 0)
    print()
N = int(input())
a_list = list(map(int,input().split()))
b_list = list(map(int,input().split()))

win, winner_cnt, ans = 0,0,0
rcp = {1:3, 2:1, 3:2}

for n in range(N):
    if a_list[n] == b_list[n]:
        if win == 1:
            win = 2
            winner_cnt = 1
        elif win == 2:
            win = 1
            winner_cnt = 1
    elif rcp[a_list[n]] == b_list[n]:
        if win == 1:
            winner_cnt += 1
        else:
            win = 1
            winner_cnt = 1
    elif rcp[a_list[n]] != b_list[n]:
        if win == 2:
            winner_cnt += 1
        else:
            win = 2
            winner_cnt = 1
    ans = max(ans, winner_cnt)
print(ans)
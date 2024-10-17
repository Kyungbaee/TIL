
def solve(e):
    global b_cnt
    global ans

    if e==N:
        ans = max(ans, b_cnt)
        return
    
    if egg[e][0]<=0 or b_cnt == N-1:
        solve(e+1)
        return
    
    for i in range(N):
        if i==e or egg[i][0]<=0: continue

        egg[e][0] -= egg[i][1]
        egg[i][0] -= egg[e][1]
        if(egg[e][0] <= 0): b_cnt +=1
        if(egg[i][0] <= 0): b_cnt +=1
        solve(e+1)
        if(egg[e][0] <= 0): b_cnt -=1
        if(egg[i][0] <= 0): b_cnt -=1
        egg[e][0] += egg[i][1]
        egg[i][0] += egg[e][1]



N = int(input())
egg = [list(map(int, input().split())) for _ in range(N)]
ans, b_cnt = 0, 0

solve(0)
print(ans)
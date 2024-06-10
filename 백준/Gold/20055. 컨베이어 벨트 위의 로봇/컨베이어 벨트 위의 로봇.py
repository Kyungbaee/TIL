def solve(N, K):
    global start_p

    #1
    start_p += (2*N-1)
    end_p = (start_p+(N-1))%(2*N)

    if v_list[end_p]:
        v_list[end_p] = 0

    #2
    # print((start_p+4)%6, start_p%6)
    for i in range(start_p+(2*N-1), start_p-1, -1):
        i %= (2*N)

        if v_list[i] and c_list[(i+1)%(2*N)]>0 and v_list[(i+1)%(2*N)] == 0:
            c_list[(i+1)%(2*N)] -= 1

            if (i+1)%(2*N) != end_p:
                v_list[(i+1)%(2*N)] = 1
            v_list[i] = 0
    #3
    if c_list[start_p%(2*N)] > 0:
        v_list[start_p%(2*N)] = 1
        c_list[start_p%(2*N)] -= 1

    #4
    if c_list.count(0) >= K:
        return 1
    else:
        return 0

N, K = map(int, input().split())
c_list = list(map(int,input().split()))
v_list = [0]*2*N
start_p, ans = 0, 1

while True:
    if solve(N, K):
        break
    else:
        ans += 1

print(ans)
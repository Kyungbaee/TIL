for case in range(10):
    N = int(input())
    hlist = list(map(int, input().split()))
    ans = 0

    for i in range(2,N-2):
        check = sorted(hlist[i-2:i]+hlist[i+1:i+3])
        if hlist[i] > check[-1]:
            ans += hlist[i]-check[-1]
    print(f"#{case+1} {ans}")

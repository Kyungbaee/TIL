T = int(input())

for case in range(T):
    A,B,C = map(int, input().split())
    ans = 0

    if (C <= 2) or (B <= 1):
        ans = -1
    else:
        if B >= C:
            ans += B-C+1
            B = C-1
        if A >= B:
            ans += A-B+1

    print(f"#{case+1} {ans}")
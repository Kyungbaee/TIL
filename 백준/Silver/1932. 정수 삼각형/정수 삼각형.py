def solve(i):
    for idx in range(len(t[i])):
        l, r = idx-1, idx

        if l>=0 and r<len(t[i-1]):
            t[i][idx] += max(t[i-1][l], t[i-1][r])
        elif l<0:
            t[i][idx] += t[i-1][r]
        elif r>=len(t[i-1]):
            t[i][idx] += t[i-1][l]

    return

N = int(input())
t = [list(map(int, input().split())) for _ in range(N)]


for i in range(1, len(t)):
    solve(i)
print(max(t[-1]))
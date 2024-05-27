N = int(input())
T = [[1]*10 for _ in range(N+1)]

for i in range(2, N+1):
    for j in range(10):
        T[i][j] = sum(T[i-1][-(10-j):])
print(sum(T[N])%10007)
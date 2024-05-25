N = int(input())
F = [0]*46
F[1] = 1

for i in range(2,N+1):
    F[i] = F[i-1]+F[i-2]
print(F[N])
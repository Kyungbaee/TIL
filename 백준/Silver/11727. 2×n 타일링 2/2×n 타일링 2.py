N = int(input())
T = [0]*1001
T[1], T[2] = 1, 3
for i in range(3, N+1):
    T[i] = T[i-1] + T[i-2]*2
print(T[N]%10007)
N = int(input())
T = [[1]*10 if i == 1 else [0]*10 for i in range(101)]

for i in range(1,N+1):
    for j in range(0,10):
        if j+1 <= 9:
            T[i][j] += T[i-1][j+1]
        if j-1 >= 0:
            T[i][j] += T[i-1][j-1]
print(sum(T[i][1:])%(1000000000))
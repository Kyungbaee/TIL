from sys import stdin

T = int(stdin.readline())

def fibonacci(target):
    if (target == 0):
        return [1,0]
    elif (target == 1):
        return [0,1]
    else:
        return [L[target-1][0] + L[target-2][0], L[target-1][1] + L[target-2][1]]

for test_case in range(T):
    num = int(stdin.readline())
    L = []

    for i in range(num+1):
        L.append(fibonacci(i))

    print(L[-1][0], L[-1][1])

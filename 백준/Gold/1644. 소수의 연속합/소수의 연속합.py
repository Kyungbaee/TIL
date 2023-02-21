from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())
    answer = 0
    eratos = [0]
    Max = 4000001
    check = [True] * Max
    check[0],check[1] = False,False

    for num in range(2,Max):
        if check[num] == False:
            continue
        eratos.append(eratos[-1]+num)

        remove = 2
        while num * remove < Max:
            check[num*remove] = False
            remove += 1

    Left,Right = 0,1

    while(Right < len(eratos)):
        sum = eratos[Right] - eratos[Left]
        if sum < N:
            Right += 1       
        elif sum == N :
            answer += 1
            Right += 1
        elif sum > N:
            Left += 1

    print(answer)
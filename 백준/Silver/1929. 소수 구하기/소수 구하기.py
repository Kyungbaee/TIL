from sys import stdin

if __name__ == "__main__":
    M, N = map(int, stdin.readline().split())
    check = [True] * (N+1)
    check[0], check[1] = False, False

    for i in range(2, N+1):
        if check[i] == False:
            continue

        remove = 2
        while(i * remove < N+1):
            check[i*remove] = False
            remove += 1
    
    for idx in range(M,N+1):
        if check[idx]:
            print(idx)
from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())

    cnt = 0
    for num in list(map(int, stdin.readline().split())):
        if num > 1:
            cnt += 1
            for i in range(2,num):
                if num % i == 0:
                    cnt -= 1
                    break
    print(cnt)
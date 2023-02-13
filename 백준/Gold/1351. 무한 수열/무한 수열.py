from sys import stdin

def func(num):
    if num == 0:
        return 1
    else:
        if num//P not in num_dict:
            num_dict[num//P] = func(num//P)

        if num//Q not in num_dict:
            num_dict[num//Q] = func(num//Q)

        return num_dict[num//P] + num_dict[num//Q]

if __name__ == "__main__":
    N, P, Q = map(int, stdin.readline().split())

    num_dict = {}
    print(func(N))
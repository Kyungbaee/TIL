from sys import stdin
from collections import deque

def print_list(N_q):
    print("[", end = "")
    for i, n in enumerate(N_q):
        print(int(n), end = "")
        if i != len(N_q)-1:
            print(",", end="")
    print("]")

if __name__ == "__main__":
    T = int(stdin.readline())

    for _ in range(T):
        funcs = str(stdin.readline().strip()).replace("RR","")
        N = int(stdin.readline())       
        data = stdin.readline().strip()[1:-1]
        if data != "":
            data = data.split(",")
        N_q = deque(data)

        Reverse = 0
        error_check = 1
        for func in funcs:
            if func == "R":
                if Reverse == 0:
                    Reverse = 1
                else:
                    Reverse = 0

            elif func == "D":
                if (len(N_q) == 0) or (N == 0):
                    print("error")
                    error_check = 0
                    break
                else:
                    if Reverse:
                        N_q.pop()
                    else:
                        N_q.popleft()


        if error_check:
            if Reverse:
                N_q.reverse()
            print_list(N_q)
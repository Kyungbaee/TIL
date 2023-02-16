from sys import stdin
from collections import deque

# 최종 결과 출력
def print_list(N_q):
    print("[", end = "")
    for i, n in enumerate(N_q):
        print(int(n), end = "")
        if i != len(N_q)-1:
            print(",", end="")
    print("]")

if __name__ == "__main__":
    # 테스트 케이스의 개수 T 
    T = int(stdin.readline())

    for _ in range(T):
        # 수행할 함수 funcs, 1 <= funcs의 길이 <= 100,000
        funcs = str(stdin.readline().strip()).replace("RR","")
        # 배열에 들어있는 수의 개수 n, (0 ≤ n ≤ 100,000)
        N = int(stdin.readline())       
        # 배열에 들어있는 정수
        data = stdin.readline().strip()[1:-1]
        if data != "":
            data = data.split(",")
        N_q = deque(data)

        Reverse = 0
        error_check = 1

        for func in funcs:
            # R : 뒤집기
            if func == "R":
                if Reverse == 0:
                    Reverse = 1
                else:
                    Reverse = 0
            # D : 첫 번째 값 버리기
            elif func == "D":
                # 에러 출력
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

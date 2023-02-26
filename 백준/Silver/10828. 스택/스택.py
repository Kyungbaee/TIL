from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())

    num_list = []
    for _ in range(N):
        for command in list(stdin.readline().split()):
            if str.isdigit(command):
                num_list.append(command)
            if command == "pop":
                if len(num_list):
                    print(num_list.pop())
                else:
                    print(-1)
            if command == "size":
                print(len(num_list))
            if command == "empty":
                if len(num_list):
                    print(0)
                else:
                    print(1)
            if command == "top":
                if len(num_list):
                    print(num_list[-1])
                else:
                    print(-1)
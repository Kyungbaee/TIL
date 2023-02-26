from sys import stdin
from collections import deque

if __name__ == "__main__":
    L_list = deque(stdin.readline().strip())
    R_list = deque()
    N = int(stdin.readline())

    cursor = len(L_list)
    for _ in range(N):
        command = list(stdin.readline().split())
        if len(command) > 1:
            L_list.append(command[1])
            cursor += 1
        
        if command[0] == "L" and cursor > 0:
            R_list.appendleft(L_list.pop())
            cursor -= 1
        if command[0] == "D" and cursor < len(R_list)+len(L_list):
            L_list.append(R_list.popleft())
            cursor += 1
        if command[0] == 'B' and cursor > 0:
            L_list.pop()
            cursor -= 1

    print(''.join(L_list+R_list))
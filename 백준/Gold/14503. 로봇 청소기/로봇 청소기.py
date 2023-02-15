from sys import stdin

def func_1(input_list,room):
    x = input_list[0]
    y = input_list[1]
    if room[x][y] == 0:
        room[x][y] = 2
        return 1
    return 0

def func_2(input_list,room):
    x = input_list[0]
    y = input_list[1]
    direction = input_list[2]

    ## Right
    if y+1 < M:
        if room[x][y+1] == 0:
            return 0
    ## Left
    if y > 0:
        if room[x][y-1] == 0:
            return 0   
    ## Up
    if x > 0:
        if room[x-1][y] == 0:
            return 0
    ## Down
    if x+1 < N:
        if room[x+1][y] == 0:
            return 0
        
    if (direction == 0) and (x+1 < N):
        if room[x+1][y] == 2:
            input_list[0] += 1
            return 1
    elif (direction == 1) and (y > 0):
        if room[x][y-1] == 2:
            input_list[1] -= 1
            return 1
    elif (direction == 2) and (x > 0):
        if room[x-1][y] == 2:
            input_list[0] -= 1
            return 1
    elif (direction == 3) and (y+1 < M):
        if room[x][y+1] == 2:
            input_list[1] += 1
            return 1
    return 2
    
def func_3(input_list,room):
    x = input_list[0]
    y = input_list[1]
    
    if input_list[2] == 0:
        input_list[2] = 3
    else:
        input_list[2] -= 1

    direction = input_list[2]

    if (direction == 0) and (x > 0):
        if room[x-1][y] == 0:
            input_list[0] -= 1
            return 1
    elif (direction == 1) and (y+1 < M):
        if room[x][y+1] == 0:
            input_list[1] += 1
            return 1
    elif (direction == 2) and (x+1 < N):
        if room[x+1][y] == 0:
            input_list[0] += 1
            return 1
    elif (direction == 3) and (y > 0):
        if room[x][y-1] == 0:
            input_list[1] -= 1
            return 1
    else:
        return 0


if __name__ == "__main__":
    N, M = map(int, stdin.readline().split())
    input_list = list(map(int, stdin.readline().split()))
    clean_cnt = 0

    room = []
    for x in range(N):
        line = []
        for y in map(int, stdin.readline().split()):
            line.append(y)
        room.append(line)
    
    clean_cnt += func_1(input_list,room)

    while(True):
        case = func_2(input_list,room)
        if case == 0:
            if func_3(input_list,room):
                clean_cnt += func_1(input_list,room)
        elif case == 1:
            continue
        elif case == 2:
            break
    print(clean_cnt)
from sys import stdin

## 1번 기능 : 해당 칸 청소
def func_1(input_list,room):
    x = input_list[0]
    y = input_list[1]
    if room[x][y] == 0:
        room[x][y] = 2
        return 1
    return 0

## 2번 기능 : 상하좌우가 청소된 경우
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

## 2-1 : 후진
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
## 2-2 : 작동 멈춤
    return 2
    
## 3번 기능 : 상하좌우 중 청소할 칸이 있는 경우
def func_3(input_list,room):
    x = input_list[0]
    y = input_list[1]
    
    if input_list[2] == 0:
        input_list[2] = 3
    else:
        input_list[2] -= 1

## 3-1 : 반시계 90도 회전
    direction = input_list[2]

## 3-2 : 청소할 칸으로 한칸 전진
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
	## 방의 크기 N, M
    N, M = map(int, stdin.readline().split())
    ## 처음 로봇 청소기 좌표 및 방향
    input_list = list(map(int, stdin.readline().split()))
    clean_cnt = 0

    room = []
    for x in range(N):
        line = []
        ## 각 장소의 상태
        for y in map(int, stdin.readline().split()):
            line.append(y)
        room.append(line)
    
    clean_cnt += func_1(input_list,room)

## 청소 작동
    while(True):
        case = func_2(input_list,room)
        if case == 0:
            if func_3(input_list,room):
                clean_cnt += func_1(input_list,room)
        elif case == 1:
            continue
        elif case == 2:
            break
            
## 청소한 칸 출력
    print(clean_cnt)

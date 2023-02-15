from sys import stdin

# 좌표 넣을 구조체
class XY:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# 바이러스 확산
def BFS(copy_list, two):
    Q = []
    for check in two:
        Q.append(check)

	## 상하좌우로 확산
        while(len(Q) != 0):                    
            ## RIGHT
            if (Q[0].y < M-1):
                if copy_list[Q[0].x][Q[0].y+1] == 0:
                    copy_list[Q[0].x][Q[0].y+1] = 2
                    Q.append(XY(Q[0].x,Q[0].y+1))        

            ## DOWN
            if (Q[0].x < N-1):
                if copy_list[Q[0].x+1][Q[0].y] == 0:
                    copy_list[Q[0].x+1][Q[0].y] = 2
                    Q.append(XY(Q[0].x+1,Q[0].y))

            ## LEFT
            if (Q[0].y > 0):
                if copy_list[Q[0].x][Q[0].y-1] == 0:
                    copy_list[Q[0].x][Q[0].y-1] = 2
                    Q.append(XY(Q[0].x,Q[0].y-1))          
            
            ## UP
            if (Q[0].x > 0):
                if copy_list[Q[0].x-1][Q[0].y] == 0:
                    copy_list[Q[0].x-1][Q[0].y] = 2
                    Q.append(XY(Q[0].x-1,Q[0].y))
            
            del Q[0]

    result = 0
    for c_item in copy_list:
        result += c_item.count(0)   
    return result


if __name__ == "__main__":
## 지도의 세로 크기 N, 가로 크기 M
    N, M = map(int, stdin.readline().split())
    map_list = []
    two_list = []
    answer = 0

    for x in range(N):
    ## N개의 지도의 모양
        numbers = list(map(int, stdin.readline().split()))
        line = []
        for y, num in enumerate(numbers):
            if num == 2:
                two_list.append(XY(x,y))
            line.append(num)
        map_list.append(line)

## 첫 번째 벽 경우의 수
    for first in range(N*M):
        if map_list[first//M][first%M] == 0:
            map_list[first//M][first%M] = 1
	## 두 번째 벽 경우의 수
            for sec in range(first+1, N*M):
                if map_list[sec//M][sec%M] == 0:
                    map_list[sec//M][sec%M] = 1
		## 세 번째 벽 경우의수
                    for trd in range(sec+1, N*M):
                        if map_list[trd//M][trd%M] == 0:
                            map_list[trd//M][trd%M] = 1

                            copy_list = [maps.copy() for maps in map_list]
                            cnt = BFS(copy_list, two_list)
                            answer = answer if answer > cnt else cnt
                            map_list[trd//M][trd%M] = 0
                    
                    map_list[sec//M][sec%M] = 0
            map_list[first//M][first%M] = 0

## 최대 빈칸의 수
    print(answer)

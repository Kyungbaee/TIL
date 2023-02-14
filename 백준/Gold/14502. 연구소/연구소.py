from sys import stdin

class XY:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def BFS(copy_list, two):
    Q = []
    for check in two:
        Q.append(check)

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
    N, M = map(int, stdin.readline().split())
    map_list = []
    two_list = []
    answer = 0

    for x in range(N):
        numbers = list(map(int, stdin.readline().split()))
        line = []
        for y, num in enumerate(numbers):
            if num == 2:
                two_list.append(XY(x,y))
            line.append(num)
        map_list.append(line)

    for first in range(N*M):
        if map_list[first//M][first%M] == 0:
            map_list[first//M][first%M] = 1

            for sec in range(first+1, N*M):
                if map_list[sec//M][sec%M] == 0:
                    map_list[sec//M][sec%M] = 1

                    for trd in range(sec+1, N*M):
                        if map_list[trd//M][trd%M] == 0:
                            map_list[trd//M][trd%M] = 1

                            copy_list = [maps.copy() for maps in map_list]
                            cnt = BFS(copy_list, two_list)
                            answer = answer if answer > cnt else cnt
                            map_list[trd//M][trd%M] = 0
                    
                    map_list[sec//M][sec%M] = 0
            map_list[first//M][first%M] = 0


    print(answer)
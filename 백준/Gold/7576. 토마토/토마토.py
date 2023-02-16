from sys import stdin
from collections import deque

class XY:
    def __init__(self,x,y):
        self.x = x
        self.y = y

def BFS(good_t, day):
    add_q = deque()

    while(True):
        if len(good_t) == 0:
            if len(add_q) != 0:
                good_t.extend(add_q)
                add_q.clear()
                day += 1
            else:
                break

        x = good_t[0].x
        y = good_t[0].y
        
        ## Up
        if x > 0:
            if box[x-1][y] == 0:
                box[x-1][y] = 1
                add_q.append(XY(x-1,y))
        ## Left
        if y > 0:
            if box[x][y-1] == 0:
                box[x][y-1] = 1
                add_q.append(XY(x,y-1))
        ## Down
        if x+1 < N:
            if box[x+1][y] == 0:
                box[x+1][y] = 1
                add_q.append(XY(x+1,y))
        ## Right
        if y+1 < M:
            if box[x][y+1] == 0:
                box[x][y+1] = 1
                add_q.append(XY(x,y+1))
        
        good_t.popleft()

    return day

if __name__ == "__main__":
    # M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수
    # 2 ≤ M,N ≤ 1,000
    M, N = map(int, stdin.readline().split())
    good_t = deque()
    box = []
    day = 0
    for x in range(N):
        # 토마토 정보
        # 1 : 익은 토마토, 0 : 익지 않은 토마토, -1 : 토마토가 들어있지 않은 칸
        box_list = []
        for y,tomato in enumerate(map(int, stdin.readline().split())):
            if tomato == 1:
                good_t.append(XY(x,y))
            box_list.append(tomato)
        box.append(box_list)
    if len(good_t) == 0:
        print(-1)
    else:
        day = BFS(good_t, day)

        for idx, tomato_l in enumerate(box):
            if tomato_l.count(0) != 0:
                print(-1)
                break
            
            if idx == len(box)-1:
                print(day)
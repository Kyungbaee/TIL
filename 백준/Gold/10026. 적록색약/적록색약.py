from sys import stdin
from collections import deque

# 좌표 구조체
class XY:
    def __init__(self,x,y,color):
        self.x = x
        self.y = y
        self.color = color

def BFS(color_XY,color_dict,feature):
    x = color_XY.x
    y = color_XY.y
    if visited[x][y]:
        q.append(color_XY)
        visited[x][y] = False

    while(len(q) != 0):
        color = q.popleft()
        i,j,c = color.x,color.y,color.color
		
        # 상하좌우 탐색 + feature==1(적록색약) 일 경우, 빨강 == 초록
        if i > 0:
            U_c = color_list[i-1][j].color
            if ( U_c == c or (feature and (c=="R" or c=="G") and (U_c=="R" or U_c == "G"))) and visited[i-1][j]:
                q.append(color_list[i-1][j])
                visited[i-1][j] = False
        if j > 0:
            L_c = color_list[i][j-1].color
            if (L_c == c or (feature and (c=="R" or c=="G") and (L_c=="R" or L_c == "G"))) and visited[i][j-1]:
                q.append(color_list[i][j-1])
                visited[i][j-1] = False
        if i+1 < N:
            D_c = color_list[i+1][j].color
            if (D_c == c or (feature and (c=="R" or c=="G") and (D_c=="R" or D_c == "G"))) and visited[i+1][j]:
                q.append(color_list[i+1][j])
                visited[i+1][j] = False
        if j+1 < N:
            R_c = color_list[i][j+1].color
            if (R_c == c or (feature and (c=="R" or c=="G") and (R_c=="R" or R_c == "G"))) and visited[i][j+1]:
                q.append(color_list[i][j+1])
                visited[i][j+1] = False

	# 딕셔너리의 색깔 별 영역의 수
    color_dict[color_list[x][y].color] += 1

# 초기화
def init():
    for i in range(N):
        for j in range(N):
            visited[i][j] = True

# 일반인
def func_nomal():
    for x in range(N):
        for y in range(N):
            if visited[x][y]:
                BFS(color_list[x][y],color_dict,0)
                
# 적록색약
def func_special():
    for x in range(N):
        for y in range(N):
            if visited[x][y]:
                BFS(color_list[x][y],color_dict,1)

if __name__ == "__main__":
    N = int(stdin.readline())
    visited, color_list = [], []
    color_dict = {"R":0, "G":0, "B":0}
    for i in range(N):
        color_row = []
        for j,c in enumerate(list(stdin.readline().strip())):
            color_row.append(XY(i,j,c))
        color_list.append(color_row)
        visited.append([ True for _ in range(N)])

	# BFS에 사용할 덱
    q = deque()
    func_nomal()
    # 일반인 영역의 수
    print(color_dict["R"]+color_dict["G"]+color_dict["B"], end = " ")
    init()
    color_dict = {"R":0, "G":0, "B":0}
    func_special()
    # 적록색약 영역의 수
    print(color_dict["R"]+color_dict["G"]+color_dict["B"])

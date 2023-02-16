from sys import stdin
from itertools import combinations

# 좌표 구조체
class XY:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# 도시의 치킨 거리 계산
def cal_distance(copy_map,bf_list):
    length = len(copy_map)
    chicken_road = 0

    for x in range(length):
        for y in range(length):
            short_d = 0
            if copy_map[x][y] == 1:
                for bf in bf_list:
                    dis = abs(bf.x - x) + abs(bf.y - y)
                    if short_d == 0:
                        short_d = dis
                    else:
                        short_d  = short_d if short_d <= dis else dis
                chicken_road += short_d
    return chicken_road

if __name__ == "__main__":
    # N * N의 도시, 최대 M개의 치킨집
    N, M = map(int, stdin.readline().split())
    chicken_map = []
    chicken_list = []
    visited = []

    min_length = 0

    # 도시 지도 정보 및 치킨집 위치 삽입
    for x in range(N):
        map_info = []
        for y,num in enumerate(map(int, stdin.readline().split())):
            if num == 2:
                chicken_list.append(XY(x,y))
                map_info.append(0)
            else:
                map_info.append(num)
            visited.append(0)
        chicken_map.append(map_info)

    # COMBINATION을 통한 모든 치킨집 경우의 수, 브루트포스 알고리즘
    for bf_list in list(combinations(chicken_list,M)):
        copy_map = chicken_map.copy()
        for bf in bf_list:
            copy_map[bf.x][bf.y] = 2
        if min_length == 0:
            min_length = cal_distance(copy_map, bf_list)
        else:
            cal_d = cal_distance(copy_map, bf_list)
            min_length = cal_d if min_length > cal_d else min_length

    print(min_length)

"""
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 

이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 
조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
"""

# math 모듈 불러오기
import math

# 테스트 케이스 개수 T 입력
T = int(input())
coordinate_list = []

if __name__ == "__main__":
    # x1,y1,r1,x2,y2,r2 순서의 테스트 케이스 입력 받기
    for testcase in range(T):
        coordinate_list.append(list(map(int, input().split())))
    
    
    for coordinate in coordinate_list:
        x1 = coordinate[0]
        y1 = coordinate[1]
        r1 = coordinate[2]
        x2 = coordinate[3]
        y2 = coordinate[4]
        r2 = coordinate[5]

        # 입력 받은 좌표 사이의 거리 구하기
        distance = math.sqrt((x2-x1) ** 2 + (y2-y1) **2)
        
        # 두 원이 일치할 때
        if (distance == 0) and (r1 == r2):
            print(-1)
        # 두 원이 외접할 때
        elif (r1+r2) == distance :
            print(1)
        # 두 원이 내접할 때
        elif ((distance + r1) == r2) or ((distance + r2) == r1) :
            print(1)
        # 두 원이 서로 떨어져 있고 만나지 않을 때
        elif abs(r2-r1) > distance :
            print(0)
        # 한 원이 다른 원의 내부에 있고 두 원이 만나지 않을 때
        elif abs(r1+r2) < distance :
            print(0)
        else :
            print(2)

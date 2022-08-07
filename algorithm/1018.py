"""
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 
어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 
지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 
따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 
당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.
"""

#  N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수 입력
V,W = map(int, input().split())

chess = []
count = 0
count_list = []
color_list = ["W","B"]

if __name__ == "__main__" :
  
    # 보드판 입력
    for i in range(V):
        BW = str(input())
        chess.append(BW)

    
    # 보드판의 시작이 백색 or 흑색
    for color in color_list:
      
        # baseV, baseW는 보드판이 8x8가 아닐 경우, 옮겨서 탐색
        for baseV in range(V-8+1):
            for baseW in range(W-8+1):
                
                # 8x8 보드판 짝수 열 탐색
                for vertical in range(0,8,2):
                    for width in range(8):
                        check = str(chess[baseV+vertical])[baseW+width]
                        # 색이 번갈아 칠해져있는지 탐색
                        if ((baseW+width) % 2) == (baseW % 2):
                            if color != check:
                                count += 1
                        elif (baseW+width) % 2 != (baseW % 2):
                            if color == check:
                                count += 1
                                
                # 8x8 보드판 홀수 열 탐색
                for vertical in range(1,8,2):
                    for width in range(8):
                        check = str(chess[baseV+vertical])[baseW+width]
                        # 색이 번갈아 칠해져있는지 탐색
                        if (baseW+width) % 2 == (baseW % 2):
                            if color == check:
                                count += 1
                        elif (baseW+width) % 2 != (baseW % 2):
                            if color != check:  
                                count += 1
                # 경우의 수 마다 잘못 칠해져 있는 count 저장
                count_list.append(count)
                count = 0
                
    # 가장 적은 경우의 수 출력
    print(min(count_list))



def solution(brown, yellow):
    ## 노란색 카펫의 넓이을 기준으로 탐색
    for w in range(yellow,0,-1):
        ## yellow % w == 0 → 길이 대비 가로 세로의 비율이 정수 나누어 떨어지는 경우
        ## brown == (w*2+(yellow//w)*2+4) → 노란색 카펫의 넓이, 높이가 정해졌을 시, 갈색 카펫 길이
        if yellow % w == 0 and brown == (w*2+(yellow//w)*2+4):
            return [w+2, (yellow//w)+2]
def change_dice(way, dice):
    new_dice = [0]*6
    for idx, w in enumerate(way):
        new_dice[w] = dice[idx]
    dice = new_dice
    return dice

N, M, x, y, K = map(int, input().split())
m_list = [list(map(int, input().split())) for _ in range(N)]
move = list(map(int, input().split()))
dice = [0]*6

# 주사위 방향 및 좌표 이동
dice_way = [(0,5,2,4,1,3),(0,4,2,5,3,1),(3,0,1,2,4,5),(1,2,3,0,4,5)]
move_dice = [(0,1),(0,-1),(-1,0),(1,0)]

for m in move:
    dx, dy = move_dice[m-1]
    nx, ny = x+dx, y+dy
    if 0<=nx<N and 0<=ny<M:
        x, y = nx, ny
        dice = change_dice(dice_way[m-1],dice)
        # 이동한 칸이 0일 경우, 바닥면 숫자 지도에 복사
        if not m_list[nx][ny]:
            m_list[nx][ny] = dice[3]
        # 이동한 칸이 0이 아닐 경우, 지도 숫자를 바닥면에 복사 및 지도 0으로 초기화
        elif m_list[nx][ny]:
            dice[3] = m_list[nx][ny]
            m_list[nx][ny] = 0
        # 이동 후, 주사위 윗면 출력
        print(dice[1])
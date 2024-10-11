# 1 (+6) 7 (+12) 19 (+18) 37 (+24) 61
target = int(input())
move = 1
room_cnt = 1

while(True):
    if room_cnt>=target:
        break
    room_cnt += 6*move
    move += 1
print(move)
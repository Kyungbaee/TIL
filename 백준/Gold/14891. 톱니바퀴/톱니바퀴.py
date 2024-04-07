# import sys
# sys.stdin = open("testcase.txt","r")


def spin(top, idx, dir):
    if dir == -1:
        top[idx] = (top[idx]+1)%8
    else:
        top[idx] = (top[idx]+7)%8
    

wheel = []
top = [0]*4

for i in range(4):
    tcase = list(map(int, input()))
    wheel.append(tcase)

K = int(input())

for _ in range(K):
    num, dir = map(int, input().split())
    cycle_list = []
    cycle_list.append((num-1, dir))

    # Right spin
    for i in range(num, 4):
        if wheel[i-1][(top[i-1]+2)%8] != wheel[i][(top[i]+6)%8]:
            if (i+1-num)%2 == 1:
                # spin(top, i, dir*-1)
                cycle_list.append((i, dir*-1))
            else:
                # spin(top, i, dir)
                cycle_list.append((i, dir))
        else:
            break

    # Left spin
    for i in range(num, 1, -1):
        if wheel[i-1][(top[i-1]+6)%8] != wheel[i-2][(top[i-2]+2)%8]:

            if (num-i+1)%2 == 1:
                cycle_list.append((i-2, dir*-1))
            else:
                cycle_list.append((i-2, dir))
        else:
            break

    for i, d in cycle_list:
        spin(top, i, d)

print(wheel[0][top[0]]*1 + wheel[1][top[1]]*2 + wheel[2][top[2]]*4 + wheel[3][top[3]]*8)
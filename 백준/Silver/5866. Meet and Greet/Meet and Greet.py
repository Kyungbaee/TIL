B, E = map(int, input().split())
B_list = [list(input().split()) for _ in range(B)]
E_list = [list(input().split()) for _ in range(E)]
v_list,v_list2, time, move = [0], [0], 0, 0
moo = 0

for b, w in B_list:
    for _ in range(int(b)):
        time += 1
        if w == 'L':
            move -= 1
        else:
            move += 1
        v_list.append(move)

time, move = 0,0
for e, w in E_list:
    for _ in range(int(e)):
        time += 1
        if w == 'L':
            move -= 1
        else:
            move += 1
        v_list2.append(move)

for check in range(1,min(len(v_list), len(v_list2))):
    if v_list[check] == v_list2[check] and v_list[check-1] != v_list2[check-1]:
        moo += 1

for check in range(min(len(v_list), len(v_list2)), max(len(v_list), len(v_list2))):
    if len(v_list) > len(v_list2) and v_list[check] == v_list2[-1]:
        moo += 1
    elif len(v_list) < len(v_list2) and v_list2[check] == v_list[-1]:
        moo += 1
print(moo)
T = int(input())
c_list = [list(input().split()) for _ in range(T)]

for c in c_list:
    num = float(c[0])
    for idx in range(1,len(c)):
        if c[idx] == '@':
            num *= 3
        elif c[idx] == '%':
            num += 5
        elif c[idx] == '#':
            num -= 7
    split_num = str(num).split('.')
    if len(split_num[1])<2:
        split_num[1] += '0'
    print(split_num[0]+'.'+split_num[1][:2])
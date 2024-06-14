T = int(input())
t_lst = [list(map(int,input().split())) for _ in range(T)]

for t in t_lst:
    A, B = t
    a_dict, b_dict = {}, {}

    div, center = 2, A//2
    while div <= center:
        if A % div == 0:
            if a_dict.get(div):
                a_dict[div] += 1
            else:
                a_dict[div] = 1
            A = A//div
        else:
            div += 1

    div, center = 2, B//2
    while div <= center:
        if B % div == 0:
            if b_dict.get(div):
                b_dict[div] += 1
            else:
                b_dict[div] = 1
            B = B//div
        else:
            div += 1

    if len(a_dict)==0 or len(b_dict)==0:
        if max(t[0],t[1])%min(t[0],t[1])==0:
            print(max(t[0],t[1]))
        else:
            print(t[0]*t[1])
        continue

    ans, center = 1, max(t[0],t[1])//2
    for idx in range(2,center+1):
        a_num, b_num = a_dict.get(idx), b_dict.get(idx)
        if a_num and b_num:
            ans *= (idx**max(a_num,b_num))
        elif a_num:
            ans *= (idx**a_num)
        elif b_num:
            ans *= (idx**b_num)
    print(ans)
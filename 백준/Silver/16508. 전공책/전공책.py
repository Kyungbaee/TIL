import itertools

T = list(input())
len_T = int(input())
book_dict, ans = {}, -1
for _ in range(len_T):
    item = input().split()
    book_dict[item[0]] = []
    for word in list(item[1]):
        if word in T:
            book_dict[item[0]].append(word)
for item in book_dict.items():
    cnt_dict = {}
    for cnt in item[1]:
        if cnt_dict.get(cnt):
            cnt_dict[cnt] += 1
        else:
            cnt_dict[cnt] = 1
    book_dict[item[0]] = cnt_dict
cnt_dict={}
for i in T:
    if cnt_dict.get(i):
        cnt_dict[i] += 1
    else:
        cnt_dict[i] = 1
T = cnt_dict.copy()
book_dict = sorted(book_dict.items(), key=lambda x:x[0])

for i in range(1,len_T+1):
    combis = list(itertools.combinations(book_dict, i))
    for combi in combis:
        cnt_dict, sum_cost = {},0
        for com in combi:
            sum_cost += int(com[0])
            for key in com[1].keys():
                if cnt_dict.get(key):
                    cnt_dict[key] += com[1][key]
                else:
                    cnt_dict[key] = com[1][key]
        check = 1
        for key in T.keys():
            if cnt_dict.get(key)==None or T[key] > cnt_dict[key]:
                check = 0
                break
        if check:
            if ans == -1:
                ans = sum_cost
            else:
                ans = min(sum_cost, ans)
print(ans)
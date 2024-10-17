def solve(cnt, cur):
    if cnt == L:
        spell_cnt = 0
        for a in ans_list:
            if a in ('a','e','i','o','u'): spell_cnt += 1
        
        if spell_cnt>=1 and (L-spell_cnt)>=2:
            print(''.join(ans_list))
        return

    for i in range(cur, C):
        ans_list[cnt] = c_list[i]
        solve(cnt+1, i+1)

L, C = map(int, input().split())
c_list = sorted(input().split())
ans_list = [0]*L

solve(0,0)
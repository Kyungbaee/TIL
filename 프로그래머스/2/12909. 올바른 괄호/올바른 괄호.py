def solution(s):
    s_list = list(map(lambda x: 1 if x=="(" else -1, s))
    
    cnt = 0
    for ss in s_list:
        cnt += ss
        if cnt < 0: return False
    
    if cnt==0: return True
    return False
def solution(s):
    s_list = [1 if ss=="(" else -1 for ss in s ]
    
    cnt = 0
    for ss in s_list:
        cnt += ss
        if cnt < 0: return False
    
    if cnt==0: return True
    return False
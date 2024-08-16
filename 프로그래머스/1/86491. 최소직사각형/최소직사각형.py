def solution(sizes):
    w_max, h_max = 0,0
    ## 세로 길이와 가로 길이 중 큰 값을 가로 길이로 설정
    sizes = [[ss[1], ss[0]] if ss[0]<ss[1] else ss for ss in sizes]
    
    ## 가로 길이와 세로 길이의 MAX 탐색
    for ss in sizes:
        if w_max < ss[0]: w_max = ss[0]
        if h_max < ss[1]: h_max = ss[1]
    
    return w_max*h_max
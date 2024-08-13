def solution(sizes):
    w_max, h_max = 0,0
    sizes = [[ss[1], ss[0]] if ss[0]<ss[1] else ss for ss in sizes]
    
    for ss in sizes:
        if w_max < ss[0]: w_max = ss[0]
        if h_max < ss[1]: h_max = ss[1]
    
    return w_max*h_max
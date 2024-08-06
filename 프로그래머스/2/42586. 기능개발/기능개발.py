def func(x, y):
    if x % y == 0: return x//y
    return x//y+1
    
def solution(progresses, speeds):
    left_days = list(map(lambda x:func(100-progresses[x],speeds[x]), range(len(speeds))))
    release, answer_list = -1, []
    
    for ld in left_days:
        if release >= ld: answer_list[-1] += 1
        if release < ld:
            answer_list.append(1)
            release = ld

    return answer_list
            
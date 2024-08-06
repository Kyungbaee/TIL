def solution(priorities, location):
    ## A B C D
    ## B C D A
    ## C D A B
    ## 실행 C
    ## D A B
    ## 실행 D
    ## A B
    ## 실행 A
    ## 실행 B
    ## 실행 순서 [2, 3, 0, 1]
    answer_list, rec, start_idx = [], len(priorities), 0
    
    while(len(answer_list)<rec):
        max_value = 0
        for i in range(start_idx, start_idx+rec):
            i %= rec
            if max_value < priorities[i]: 
                max_value, start_idx = priorities[i], i
        
        priorities[start_idx] = 0
        answer_list.append(start_idx)

    return answer_list.index(location)+1
    
def solution(arr):
    check, answer_list = -1, []
    for elm in arr:
        if check != elm: answer_list.append(elm)
        check = elm
    return answer_list
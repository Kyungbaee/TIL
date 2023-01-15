def solution(arr1, arr2):
    answer = []
    
    for idx in range(len(arr1)):
        sum_list = []
        for idx2 in range(len(arr1[idx])):
            sum_list.append(arr1[idx][idx2] + arr2[idx][idx2])
        answer.append(sum_list)
    return answer
def recursive(numbers, num, cnt, target):
    global answer
    if cnt==len(numbers):
        if num==target:
            answer += 1
        return 
    
    recursive(numbers, num+numbers[cnt], cnt+1, target)
    recursive(numbers, num-numbers[cnt], cnt+1, target)
    
    return

def solution(numbers, target):
    global answer
    answer = 0
    recursive(numbers, 0, 0, target)
    return answer
'''
재귀 함수
'''
def recursive(numbers, num, cnt, target):
    global answer
    
    # N개의 숫자 설정 및 Target 값과 비교
    if cnt==len(numbers):
        if num==target:
            answer += 1
        return 
    
    # 더하거나 빼기
    recursive(numbers, num+numbers[cnt], cnt+1, target)
    recursive(numbers, num-numbers[cnt], cnt+1, target)
    
    return

def solution(numbers, target):
    global answer
    answer = 0
    recursive(numbers, 0, 0, target)
    return answer
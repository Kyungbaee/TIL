'''
answer = 0     answer = 1

L        R     L     R
↓        ↓     ↓     ↓
50 50 70 80    50 50 70 80

answer = 2     answer = 3

L  R           L,R
↓  ↓           ↓
50 50 70 80    50 50 70 80

'''

def solution(people, limit):
    people = sorted(people)
    left, right, answer = 0, len(people)-1, 0
    
    while(left <= right):
        if people[left] + people[right] <= limit:
            left += 1
        right -= 1
        answer += 1
    
    return answer
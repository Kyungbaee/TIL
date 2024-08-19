def solution(people, limit):
    people = sorted(people)
    left, right, answer = 0, len(people)-1, 0
    
    while(left <= right):
        if people[left] + people[right] <= limit:
            left += 1
        right -= 1
        answer += 1
    
    return answer
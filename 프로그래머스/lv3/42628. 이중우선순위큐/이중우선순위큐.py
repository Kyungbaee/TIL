def solution(operations):
    answer = []
    
    for cal in operations:
        spell, num = cal.split()
        
        if spell == "I":
            answer.append(int(num))
        if spell == "D" and answer:
            if num == "-1":
                answer.remove(min(answer))
            else:
                answer.remove(max(answer))
    
    if answer:
        return [max(answer),min(answer)]
    else:
        return [0,0]
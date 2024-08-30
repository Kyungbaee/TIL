def next_list(word, words):
    w_list = []
    for i in range(len(words)):
        cnt = 0
        for j in range(len(words[i])):
            if word[j] != words[i][j]:
                cnt += 1
        if cnt==1: w_list.append(words[i])

    return w_list

def solution(begin, target, words):
    cnt = 0
    
    if target not in words:
        return cnt
    
    move, visited = [], []
    move = next_list(begin, words)
    
    while move:
        begin = move.pop()
        
        if begin==target:
            return cnt+1
        
        if begin not in visited:
            visited.append(begin)
            move.extend(next_list(begin, words))
            cnt += 1
    
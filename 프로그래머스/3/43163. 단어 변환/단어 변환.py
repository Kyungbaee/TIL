'''
현재 단어를 기준으로 한 글자만 바꿔서 만들 수 있는 글자들 찾기
'''
def next_list(word, words):
    w_list = []
    for i in range(len(words)):
        cnt = 0
        for j in range(len(words[i])):
            if word[j] != words[i][j]:
                cnt += 1
        if cnt==1: w_list.append(words[i])

    return w_list

'''
DFS
'''
def solution(begin, target, words):
    cnt = 0
    
    ## 반환할 수 없는 경우
    if target not in words:
        return cnt
    
    move, visited = [], []
    move = next_list(begin, words)
    
    while move:
        begin = move.pop()
        
        ## 단어가 Target과 같은 경우
        if begin==target:
            return cnt+1
        
        if begin not in visited:
            visited.append(begin)
            move.extend(next_list(begin, words))
            cnt += 1
    
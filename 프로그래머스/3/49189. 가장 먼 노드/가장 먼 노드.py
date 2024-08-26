from collections import defaultdict, deque

'''
BFS를 이용하여 그래프 깊이 탐색
* 1번 노드부터 시작
* visited에 depth 값을 저장
'''
def search(node, n):
    visited = [0]*(n+1)
    deq = deque()
    
    visited[1] = 1
    deq.append(1)
    
    while(deq):
        v = deq.popleft()
            
        for i in node[v]:
            if not visited[i]:
                visited[i] = visited[v]+1
                deq.append(i)
    return visited
    
'''
* n개의 노드, 양방향 간선
* 1번 노드와 가장 멀리 떨어진 노드의 개수
'''
def solution(n, edge):
    answer = 0
    node = defaultdict(list)
    
    for e in edge:
        node[e[0]].append(e[1])
        node[e[1]].append(e[0])
    
    ## 가장 멀리 떨어진 max 값 필터
    ans = search(node, n)
    ans = list(filter(lambda x:x==max(ans), ans))
    return len(ans)
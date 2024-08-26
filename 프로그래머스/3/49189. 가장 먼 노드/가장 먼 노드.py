from collections import defaultdict, deque
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
    
    
def solution(n, edge):
    answer = 0
    node = defaultdict(list)
    
    for e in edge:
        node[e[0]].append(e[1])
        node[e[1]].append(e[0])
    ans = search(node, n)
    ans = list(filter(lambda x:x==max(ans), ans))
    return len(ans)
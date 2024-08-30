from collections import deque

'''
pc를 하나씩 BFS 탐색하되,
BFS 과정에서 탐색한 pc는 패스한다.
'''
def bfs(n, pc):
    visited, cnt = [0]*n, 1 
    for s in range(len(pc)):
        if not visited[s]:
            deq = deque([pc[s]])
            ## cnt 값으로 서로 다른 네트워크 구분
            visited[s] = cnt

            while deq:
                v = deq.popleft()
                for idx in range(len(v)):
                    if not visited[idx] and v[idx]:
                        deq.append(pc[idx])
                        visited[idx] = cnt
            cnt += 1
    return visited

def solution(n, computers):
    answer = len(set(bfs(n, computers)))
    return answer
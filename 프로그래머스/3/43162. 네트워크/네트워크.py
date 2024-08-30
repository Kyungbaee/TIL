from collections import deque
def bfs(n, pc):
    visited, cnt = [0]*n, 1
    for s in range(len(pc)):
        if not visited[s]:
            deq = deque([pc[s]])
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
from collections import deque, defaultdict

def bfs(x, y, l_map, idx, visited):
    move = [(0,1), (1,0), (-1,0), (0,-1)]
    deq = deque([(x, y)])
    visited[y][x], cnt = idx, 1
    
    while deq:
        dx, dy = deq.popleft()
        
        for mx, my in move:
            nx, ny = dx+mx, dy+my  
            if (0<=nx<len(l_map[0])) and (0<=ny<len(l_map)) and l_map[ny][nx]==1 and \
            not visited[ny][nx]:
                deq.append((nx,ny))
                cnt += 1
                visited[ny][nx] = idx
            
    return cnt

def solution(land):
    answer, d = 0, defaultdict(int)
    visited = [[0]*501 for _ in range(501)]
    
    idx = 1
    for x in range(len(land[0])):
        for y in range(len(land)):
            if not visited[y][x] and land[y][x]==1:
                d[idx] = bfs(x, y, land, idx, visited)
            idx += 1
            
    for x in range(len(land[0])):
        oil = set()
        for y in range(len(land)):
            if visited[y][x]:
                oil.add(visited[y][x])

        sum_oil = 0
        for o in list(oil):
            sum_oil += d[o]
        answer = max(answer, sum_oil)

    return answer
from collections import defaultdict
def solution(points, routes):
    answer = 0
    d = defaultdict(list)
    for idx, r in enumerate(routes):
        start_x, start_y, route = points[r[0]-1][0], points[r[0]-1][1], r[1:]
        d[idx].append((start_x, start_y))
        for rr in route:
            end_x, end_y = points[rr-1][0], points[rr-1][1]
            
            if start_x > end_x:
                for i in range(1, start_x-end_x+1): d[idx].append((start_x-i,start_y))
            if start_x < end_x:
                for i in range(1, end_x-start_x+1): d[idx].append((start_x+i,start_y))
            
            if d[idx]: start_x = d[idx][-1][0]
            
            if start_y > end_y:
                for i in range(1, start_y-end_y+1): d[idx].append((start_x,start_y-i))
            if start_y < end_y:
                for i in range(1, end_y-start_y+1): d[idx].append((start_x,start_y+i))
            
            if d[idx]: start_y = d[idx][-1][1]
            
    for t in range(20001):
        dd = defaultdict(int)
        for key in d.keys():
            if t >= len(d[key]): continue 
            dd[d[key][t]] += 1
        
        if dd: answer += len(list(filter(lambda x: x>1,dd.values())))
    return answer
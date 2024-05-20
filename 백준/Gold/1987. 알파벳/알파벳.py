# 1. DFS 풀이
def dfs(ci, cj, cnt):
    global ans
    ans = max(ans, cnt)

    # 4방향, 범위내, 중복값이 아닌경우
    for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
        ni,nj = ci+di, cj+dj
        if 0<=ni<R and 0<=nj<C and v[ord(arr[ni][nj])]==0:
            v[ord(arr[ni][nj])] = 1
            dfs(ni, nj, cnt+1)
            v[ord(arr[ni][nj])] = 0

R, C = map(int, input().split())
arr = list(input() for _ in range(R))

ans = 1
v = [0]*128

v[ord(arr[0][0])] = 1 # 해당 값을 사용했음(방문표시)
dfs(0, 0, 1)
print(ans)
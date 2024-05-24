from collections import deque
def bfs(si,sj,i):
    v = [0]*100
    v[i]=1
    q = deque()
    q.append((si,sj))

    while q:
        ci, cj = q.popleft()
        if abs(ci-ei)+abs(cj-ej)<=1000:
            print("happy")
            return 1

        for idx,point in enumerate(M):
            ni, nj = point
            D = abs(ci-ni)+abs(cj-nj)
            if D <= 1000 and v[idx]==0:
                q.append((ni,nj))
                v[idx]=1

def solve():
    cnt = 0
    for idx,point in enumerate(M):
        ci, cj = point
        D = abs(ci-si)+abs(cj-sj)
        if D <= 1000:
            cnt += 1
            if bfs(ci,cj,idx):
                return

    D = abs(si-ei)+abs(sj-ej)
    if D <= 1000:
        print("happy")
    else:
        print("sad")

T = int(input())
for t in range(T):

    N = int(input())
    si, sj = map(int,input().split())
    M = [list(map(int,input().split())) for _ in range(N)]
    ei, ej = map(int, input().split())

    solve()
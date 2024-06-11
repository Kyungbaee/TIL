# 가로 체크
def solve_width(si, sj, N, L):
    # 경사로 체크
    b_list = [0]*N

    for j in range(N-1):
        check = m_list[si][j] - m_list[si][j+1]
        # 높이가 1보다 클 경우 = 불가능
        if abs(check) > 1:
            return 0
        # 높이가 1이고, 아래 경사길
        elif check == 1:
            # 경사로 놓을 자리가 없는 경우
            if j+L >= N:
                return 0
            for nj in range(j+2, j+L+1):
                # 아래 경사길 놓을 수 없는 경우
                if m_list[si][j+1] != m_list[si][nj]:
                    return 0
            for nj in range(j+1, j+L+1):
                if b_list[nj]:
                    return 0
                b_list[nj] = 1
        # 높이가 1이고, 위로 경사길
        elif check == -1:
            # 경사로 놓을 자리가 없는 경우
            if j-L+1 < 0:
                return 0
            for nj in range(j-L+1, j+1):
                if b_list[nj]:
                    return 0
                b_list[nj] = 1
    return 1

def solve_height(si,sj,N,L):
    b_list = [0]*N

    for i in range(N-1):
        check = m_list[i][sj] - m_list[i+1][sj]

        # 높이가 1보다 큰 경우
        if abs(check) > 1:
            return 0
        # 아래로 경사로 놓는 경우
        elif check == 1:
            if i+L >= N:
                return 0
            for ni in range(i+2, i+L+1):
                if m_list[i+1][sj] != m_list[ni][sj]:
                    return 0
            for ni in range(i+1, i+L+1):
                if b_list[ni]:
                    return 0
                b_list[ni] = 1
        # 위로 경사로 놓는 경우
        elif check == -1:
            if i-L+1 < 0:
                return 0
            for ni in range(i-L+1, i+1):
                if b_list[ni]:
                    return 0
                b_list[ni] = 1
    return 1

N, L = map(int, input().split())
m_list = [list(map(int, input().split())) for _ in range(N)]
ans = 0

for i in range(N):
    for j in range(N):
        if j == 0:
            ans += solve_width(i,j,N,L)
        if i == 0:
            ans += solve_height(i,j,N,L)
print(ans)
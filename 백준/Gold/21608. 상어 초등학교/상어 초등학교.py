def solve(num):
    max_favorite, seat_list = -1, []
    for i in range(N):
        for j in range(N):
            if m_list[i][j] == 0:

                favorite, empty_cnt = 0, 0
                for dx, dy in ((0,1),(1,0),(0,-1),(-1,0)):
                    nx, ny = i+dx, j+dy
                    if 0<=nx<N and 0<=ny<N:
                        if m_list[nx][ny] in s_dict[num]:
                            favorite += 1
                        elif m_list[nx][ny] == 0:
                            empty_cnt += 1

                if favorite > max_favorite:
                    max_favorite = favorite
                    seat_list.clear()
                    seat_list.append((i,j,empty_cnt))
                elif favorite == max_favorite:
                    seat_list.append((i,j,empty_cnt))

    if len(seat_list) == 1:
        return seat_list[0]
    elif len(seat_list) > 1:
        seat_list = sorted(seat_list, key=lambda x:x[2], reverse= True)
        max_empty_cnt = seat_list[0][2]
        cut = len(seat_list)

        for idx in range(len(seat_list)):
            if seat_list[idx][2] < max_empty_cnt:
                cut = idx
                break

        seat_list = seat_list[:cut]
        seat_list = sorted(seat_list, key=lambda x:(x[0],x[1]))
        return seat_list[0]

def ans_cnt():
    ans = 0
    for i in range(N):
        for j in range(N):
            favorite_cnt = 0
            for dx, dy in ((0,1),(1,0),(0,-1),(-1,0)):
                nx, ny = i+dx, j+dy
                if 0<=nx<N and 0<=ny<N and m_list[nx][ny] in s_dict[m_list[i][j]]:
                    favorite_cnt += 1

            if favorite_cnt == 0:
                ans += 0
            elif favorite_cnt == 1:
                ans += 1
            elif favorite_cnt == 2:
                ans += 10
            elif favorite_cnt == 3:
                ans += 100
            elif favorite_cnt == 4:
                ans += 1000
    return ans

N = int(input())
s_dict = {}
m_list = [[0]*N for _ in range(N)]

for _ in range(N*N):
    s = list(map(int, input().split()))
    s_dict[s[0]] = s[1:]

for k in s_dict.keys():
    x,y,z = solve(k)
    m_list[x][y]=k
print(ans_cnt())
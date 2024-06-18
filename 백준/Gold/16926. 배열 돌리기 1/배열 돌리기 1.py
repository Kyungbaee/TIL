N,M,R = map(int, input().split())
m_list = [list(map(int,input().split())) for _ in range(N)]
sum_num = lambda x,y : (x[0]+y[0],x[1]+y[1])

for _ in range(R):
    c_list = [[0] * M for _ in range(N)]
    LU, LD, RU, RD = (0,0), (N-1,0), (0,M-1), (N-1,M-1)
    while LU <= LD and RU <= RD and LU <= RU and LD <= RD:
        ## 아래로
        for idx in range(LD[0]-LU[0]):
            c_list[LU[0]+idx+1][LU[1]] = m_list[LU[0]+idx][LU[1]]

        ## 오른쪽
        for idx in range(RD[1]-LD[1]):
            c_list[LD[0]][LD[1]+idx+1] = m_list[LD[0]][LD[1]+idx]

        ## 위쪽
        for idx in range(RD[0]-RU[0]):
            c_list[RD[0]-idx-1][RD[1]] = m_list[RD[0]-idx][RD[1]]

        ## 왼쪽
        for idx in range(RU[1]-LU[1]):
            c_list[RU[0]][RU[1]-idx-1] = m_list[RU[0]][RU[1]-idx]

        LU, LD, RU, RD = sum_num(LU,(1,1)),sum_num(LD,(-1,1)), sum_num(RU,(1,-1)), sum_num(RD,(-1,-1))
    m_list = c_list.copy()
for mm in m_list:
    print(*mm)
print()
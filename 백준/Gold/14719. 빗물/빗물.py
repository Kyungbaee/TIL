H, W = map(int, input().split())
h_list = list(map(int,input().split()))
draw_map = [[0]*H for _ in range(W)]
ans = 0

for w in range(W):
    for idx in range(h_list[w]):
        draw_map[w][idx]=1

for h in range(H):
    for w in range(W):
        if w < W-2 and draw_map[w][h]==1:
            search=1
            while w+search<W and draw_map[w+search][h]==0:
                search += 1
            if w+search < W and draw_map[w+search][h]==1:
                ans += (search-1)
print(ans)
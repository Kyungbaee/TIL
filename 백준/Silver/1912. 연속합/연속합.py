N = int(input())
num_list = list(map(int, input().split()))
ans = -1000

for i in range(N):
    if num_list[i] < 0:
        ans = max(ans, num_list[i])
        continue

    if num_list[i] >= 0:
        ans = max(ans, num_list[i])
        if i<N-1: num_list[i+1] += num_list[i]

print(ans)
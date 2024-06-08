N = int(input())
ans = N
for _ in range(N):
    v = [0]*300
    prv_str = ''
    a_str = input()
    for a in a_str:
        if v[ord(a)] == 0:
            v[ord(a)] = 1
            prv_str = a
        elif v[ord(a)] and prv_str == a:
            continue
        else:
            ans -= 1
            break
print(ans)
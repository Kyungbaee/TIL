def bfs():
    v = [0]*(F+1)
    q = [S]
    v[S] = 1

    while q:
        c = q.pop(0)
        if c == G:
            return v[c]-1

        for Move in (U,-D):
            Dc = c+Move
            if 0<Dc<=F and v[Dc]==0:
                q.append(Dc)
                v[Dc] = v[c]+1
    return "use the stairs"

F, S, G, U, D = map(int, input().split())

print(bfs())
n = int(input())
tv = [input() for _ in range(n)]
i, j = 0, 0

for d in range(n):
    if tv[d]=='KBS1':
        i = d
        print("4"*d, end="")
        break
    else:
        print("1", end="")

for d in range(n):
    j = d
    if tv[d]=='KBS2':
        if i>j: 
            print("1", end="")
            print("4"*d, end="")
        else:
            print("4"*(d-1), end="")
        break
    else:
        print("1", end="")
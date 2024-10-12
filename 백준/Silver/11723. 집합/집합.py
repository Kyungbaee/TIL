import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
l = [0]*21

for _ in range(n):
    c = input().split()

    if len(c)==1:
        if c[0]=='all':
            l = [1]*21
        elif c[0]=='empty':
            l = [0]*21
    else:
        if c[0]=='add':
            l[int(c[1])] = 1
        elif c[0]=='remove':
            l[int(c[1])] = 0
        elif c[0]=='check':
            print(str(l[int(c[1])])+ "\n")
        elif c[0]=='toggle':
            chk = l[int(c[1])]
            if chk:
                l[int(c[1])] = 0
            else:
                l[int(c[1])] = 1
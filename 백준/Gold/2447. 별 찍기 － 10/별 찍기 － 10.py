import sys
input = sys.stdin.readline
print = sys.stdout.write

def print_star(x,y,z):
    if (x//z)%3==1 and (y//z)%3==1:
        print(" ")
    else:
        if (z//3)==0:
            print("*")
        else:
            print_star(x,y,z//3)

    return

N = int(input())

for i in range(N):
    for j in range(N):
        print_star(i,j,N)
    print("\n")
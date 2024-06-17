N,A,B=map(int,input().split()),set(map(int,input().split())),set(map(int,input().split()))
print(len((A-B).union((B-A))))
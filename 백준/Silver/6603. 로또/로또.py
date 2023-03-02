from sys import stdin
from itertools import combinations

if __name__ == "__main__":
    while(True):
        inputs = list(map(int,stdin.readline().split()))

        if inputs[0] == 0:
            break
        
        for combi in combinations(inputs[1:],6):
            print(*combi)
        print()
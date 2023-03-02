from sys import stdin
from itertools import permutations

if __name__ == "__main__":
    N = int(stdin.readline())

    for _ in range(N):
        answer = 0
        num = int(stdin.readline())

        for i in range(0,num//2+1):
            two = ['2'] * i + ['1'] * (num - 2*i)
            answer += len(list(set(permutations(two,len(two)))))

        for i in range(1,num//3+1):
            for j in range(0,(num-(3*i))//2+1):
                three = ['3'] * i + ['2'] * j + ['1'] * (num-(3*i)-(2*j))
                answer += len(list(set(permutations(three,len(three)))))

        print(answer)
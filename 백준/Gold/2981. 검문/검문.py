from sys import stdin
from math import gcd

if __name__ == "__main__":
    N = int(stdin.readline())

    num_list = []
    for _ in range(N):
        num_list.append(int(stdin.readline()))

    num_list.sort()

    new_num_list = []

    for i in range(len(num_list)):
        if i<len(num_list)-1:
            new_num_list.append(num_list[i+1] - num_list[i])
        else:
            new_num_list.append(num_list[i]-num_list[0])

    new_num_list.sort()

    min_gcd = new_num_list[0]
    for i in range(1,len(new_num_list)):
        min_gcd = gcd(min_gcd,new_num_list[i])

    measure = set()
    for i in range(1,int(min_gcd**.5+1)):
        if min_gcd % i == 0:
            measure.add(i)
            measure.add(min_gcd//i)
    measure = measure - {1}
    print(*sorted(list(measure)))
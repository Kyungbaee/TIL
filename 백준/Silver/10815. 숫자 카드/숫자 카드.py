from sys import stdin
import heapq

def binary_search(L,R,num):
        while(L <= R):
            target = (L+R)//2
            if num_list[target] == num:
                break
            elif num_list[target] > num:
                R = target-1
            elif num_list[target] < num:
                L = target+1
        
        if num_list[target] == num:
            print(1, end = " ")
        else:
            print(0, end = " ")

if __name__ == "__main__":
    N = int(stdin.readline())
    num_list = []
    for num in list(stdin.readline().split()):
        num_list.append(int(num))
    num_list.sort()

    M = int(stdin.readline())
    L, R = 0, len(num_list)-1
    for num in list(stdin.readline().split()):
        num = int(num)
        if num > num_list[R] or num < num_list[L]:
            print(0, end = " ")
        else:
            binary_search(L,R,num)
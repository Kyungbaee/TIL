from sys import stdin

def binary_search(start,mid,end,target):
    while(start <= end):
        mid = (end+start)//2
        if num_list[mid] == target or num_list[start] == target or num_list[end] == target:
            return 1
        elif num_list[mid] > target:
            end = mid-1
        elif num_list[mid] < target:
            start = mid+1
    return 0

if __name__ == "__main__":
    N = int(stdin.readline())
    num_list = []

    for num in list(stdin.readline().split()):
        num_list.append(int(num))
    num_list.sort()
    M = int(stdin.readline())

    start, mid, end = 0, (len(num_list)-1)//2, len(num_list)-1

    for target in list(stdin.readline().split()):
        if int(target) > num_list[end] or int(target) < num_list[start]:
            print(0)
        else:
            print(binary_search(start,mid,end,int(target)))
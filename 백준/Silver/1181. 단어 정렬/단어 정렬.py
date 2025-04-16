from sys import stdin

N = int(stdin.readline())

str_set = set()
for _ in range(N):
    str_set.add(str(stdin.readline().strip()))

str_list = sorted(list(str_set), key=lambda s : (len(s), s))

for string in str_list:
    print(string)
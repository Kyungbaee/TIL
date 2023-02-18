from sys import stdin
from collections import defaultdict

if __name__ == "__main__":
    N = int(stdin.readline())
    alphabet_dict = defaultdict(int)
    result_dict = defaultdict(int)

    str_list = []
    for _ in range(N):
        str_list.append(str(stdin.readline().strip())[::-1])

    count_list = []
    for idx in range(8):
        count_list.append(defaultdict(int))

        for s in str_list:
            if len(s) > idx:
                count_list[idx][s[idx]] += 1

    for idx in range(7,-1,-1):
        if len(count_list[idx]):
            for key in count_list[idx].keys():
                alphabet_dict[key] += count_list[idx][key]*(10**idx if idx!= 0 else 1)


    number = 9
    for key in dict(sorted(alphabet_dict.items(), key=lambda item:item[1], reverse=True)).keys():
        result_dict[key] = number
        number -= 1

    for i, string in enumerate(str_list):
        string = list(string)
        for idx,s in enumerate(string[::-1]):
            string[idx] = str(result_dict[s])
        str_list[i] = int(''.join(string))
    print(sum(str_list))
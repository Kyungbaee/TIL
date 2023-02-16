from sys import stdin

if __name__ == "__main__":
    str1 = stdin.readline().strip()
    str2 = stdin.readline().strip()

    LCS_list = []
    for x in range(len(str1)+1):
        LCS = []
        for y in range(len(str2)+1):
            if (x==0) or (y==0):
                LCS.append(0)
            
            elif str1[x-1] == str2[y-1]:
                LCS.append(LCS_list[x-1][y-1]+1)
            
            elif str1[x-1] != str2[y-1]:
                LCS.append(max(LCS_list[x-1][y], LCS[-1]))
        LCS_list.append(LCS)

    print(LCS_list[-1][-1])
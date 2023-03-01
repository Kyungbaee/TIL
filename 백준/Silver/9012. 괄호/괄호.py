from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())

    for _ in range(N):
        string = stdin.readline().strip()
        cnt = 0
        if len(string)%2 or (string[0] == ")") or (string[-1] == "("):
            print("NO")
            continue
        
        repeat = len(string)//2
        while(cnt < repeat):
            string = string.replace("()","")
            cnt+=1
        
        if string == "":
            print("YES")
        else:
            print("NO")
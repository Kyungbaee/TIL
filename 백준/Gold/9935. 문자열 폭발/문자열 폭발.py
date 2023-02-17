from sys import stdin

if __name__ == "__main__":
    input_list = list(stdin.readline().strip())
    bomb_str = str(stdin.readline().strip())

    i, cnt, length = 0,0,len(bomb_str)
    result = []
    visited = [ 0 for _ in range(1000000)]

    while(i != len(input_list)):
        if visited[i] == 1:
            i += 1
            continue

        spell = input_list[i]
        result.append(spell)
        visited[i] = 1

        if (result[-1] == bomb_str[-1]) and (len(result) >= length):
            delete = 1
            for r in range(length):
                if result[-1-r] != bomb_str[-1-r]:
                    delete = 0
                    break
            
            if delete:
                for r in range(length):
                    result.pop()
                if len(result):
                    i = i-(length+1)                   
                else:
                    i=0
        i += 1

    if len(result):
        print(''.join(result))
    else:
        print("FRULA")
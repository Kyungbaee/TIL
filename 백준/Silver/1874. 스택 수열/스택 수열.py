from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())
    num_list, stack, answer_list, visited = [], [], [], [True] * N
    for _ in range(N):
        stack.append(int(stdin.readline()))
    
    idx = 0
    for compare in stack:
        while(idx < N):
            idx += 1
            if compare >= idx and visited[idx-1] and idx>0:         
                num_list.append(idx)
                answer_list.append("+")
                visited[idx-1] = False
            elif compare < idx:
                idx = num_list[-1]
                if compare < idx:
                    break
            
            if compare == idx:
                num_list.pop()
                answer_list.append("-")
                idx -= 2
                break
    
    if len(num_list):
        print("NO")
    else:
        for pm in answer_list:
            print(pm)
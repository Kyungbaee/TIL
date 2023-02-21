from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())
    num_list = []

    for num in stdin.readline().strip().split():    
        num_list.append(int(num))
    num_list = sorted(num_list)
    Left = 0
    Right = len(num_list)-1

    answer = [0,0,abs(num_list[0]+num_list[-1])]
    while(Left<Right):
        if abs(num_list[Left] + num_list[Right]) <= answer[2]:
            answer[0] = num_list[Left]
            answer[1] = num_list[Right]
            answer[2] = abs(num_list[Left] + num_list[Right])

        if answer[2] == 0:
            break

        if num_list[Left]+num_list[Right] > 0:
            Right -=1
        else:
            Left += 1
        
    print(answer[0], answer[1])
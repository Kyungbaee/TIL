from sys import stdin

if __name__ == "__main__":
    N = int(stdin.readline())

    num_list, answer_list,pass_chk  = ['3','2','1'], [], 0

    while(len(num_list) != 0):
        num = num_list.pop()
        answer_list.append(num)
        if len(answer_list) > 1 and answer_list[-1] == answer_list[-2]:
            answer_list.pop()
            pass_chk += 1

            if pass_chk == 2:
                answer_list.pop()
                pass_chk = 0
                continue
            elif pass_chk > 0:
                continue

        if len(answer_list)>3:           
            for rec in range(2, len(answer_list)//2+1):
                chk = 1
                for rep in range(1,rec+1):
                    if answer_list[-rep] != answer_list[-rep-rec]:
                        chk, pass_chk = 0, 0
                        break
                
                if chk:
                    answer_list.pop()
                    pass_chk += 1
                    break

            if pass_chk == 2:
                answer_list.pop()
                pass_chk = 0
                continue
            elif pass_chk > 0:
                continue

        for next in ['3','2','1']:
            if next != num:
                num_list.append(next)

        if len(answer_list) == N:
            print(''.join(answer_list))
            break
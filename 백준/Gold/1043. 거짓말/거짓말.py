from sys import stdin

if __name__ == "__main__":
    N, M = map(int, stdin.readline().split())
    truth = list(map(int , stdin.readline().split()))
    truth_list = []
    party_list = []

    for idx in range(1,truth[0]+1):
        truth_list.append(truth[idx])
    
    for _ in range(M):
        party_num = list(map(int , stdin.readline().split()))
        member = []
        check = False
        for idx in range(1,party_num[0]+1):
            if party_num[idx] in truth_list:
                check = True
            member.append(party_num[idx])
        
        if check:
            for i in member:
                if i not in truth_list:
                    truth_list.append(i)
            check = False
        else:
            party_list.append(member)

    cnt = 0

    while(len(truth_list) != cnt):
        check_num = truth_list[cnt]
        remove_list = []
        for idx, party in enumerate(party_list):
            if check_num in party:
                for p in party:
                    if p not in truth_list:
                        truth_list.append(p)

                remove_list.append(idx)
        
        for idx in sorted(remove_list, reverse=True):
            del party_list[idx]

        cnt += 1
    
    print(len(party_list))
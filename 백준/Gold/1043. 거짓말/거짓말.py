from sys import stdin

if __name__ == "__main__":

	## 사람의 수 N, 파티의 수 M
    N, M = map(int, stdin.readline().split())
    
    ## 이야기의 진실을 아는 사람의 수와 번호
    ## 진실을 아는 사람 또 알게될 사람은 진실 리스트에 담는다.
    truth = list(map(int , stdin.readline().split()))
    
    truth_list = []
    party_list = [] # -> 전체 파티를 담는 리스트, 반복해서 탐색할 예정

    for idx in range(1,truth[0]+1):
        truth_list.append(truth[idx])
    
    for _ in range(M):
    ## 각 파티마다 오는 사람의 수와 번호
        party_num = list(map(int , stdin.readline().split()))
        
        member = []
        check = False
        for idx in range(1,party_num[0]+1):
            if party_num[idx] in truth_list:
                check = True
            member.append(party_num[idx])
        
        ## 진실을 아는 사람이 포함된 파티
        if check:
            for i in member:
                if i not in truth_list:
                    truth_list.append(i)
            check = False
        else:
            party_list.append(member)

    cnt = 0

	## 진실을 아는 인원 리스트를 갱신해주며 파티를 걸러낸다.
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

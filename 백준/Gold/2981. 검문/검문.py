from sys import stdin
from math import gcd

if __name__ == "__main__":
	# 종이에 적을 정수 개수
    N = int(stdin.readline())

    num_list = []
    for _ in range(N):
        num_list.append(int(stdin.readline()))

	# 큰 수에서 작은 수를 빼기 위해 오름차순
    num_list.sort()

    new_num_list = []

	# 정수의 차를 구한다.
    for i in range(len(num_list)):
        if i<len(num_list)-1:
            new_num_list.append(num_list[i+1] - num_list[i])
        else:
            new_num_list.append(num_list[i]-num_list[0])

	# 최대공약수를 갱신해주기 위해 오름차순으로 정렬
    new_num_list.sort()

	# 최대 공약수 
    min_gcd = new_num_list[0]
    for i in range(1,len(new_num_list)):
        min_gcd = gcd(min_gcd,new_num_list[i])

	# 중복과 1을 제외한 공약수들 구하기
    measure = set()
    for i in range(1,int(min_gcd**.5+1)):
        if min_gcd % i == 0:
            measure.add(i)
            measure.add(min_gcd//i)
    measure = measure - {1}
    
    # 정답 출력
    print(*sorted(list(measure)))

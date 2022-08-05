"""
정수 집합 S가 주어졌을때, 다음 조건을 만족하는 구간 [A, B]를 좋은 구간이라고 한다.

A와 B는 양의 정수이고, A < B를 만족한다.
A ≤ x ≤ B를 만족하는 모든 정수 x가 집합 S에 속하지 않는다.
집합 S와 n이 주어졌을 때, n을 포함하는 좋은 구간의 개수를 구해보자.
"""

"""
- 제한 -
1 ≤ L ≤ 50
집합 S에는 중복되는 정수가 없다.
집합 S에 포함된 모든 정수는 1보다 크거나 같고, 1,000보다 작거나 같다.
1 ≤ n ≤ (집합 S에서 가장 큰 정수)
"""

# 집합 S의 크기 L 입력
L = int(input())
S = []

# 집합에 포함된 정수 입력
idx = input()
answer = 0

if __name__ == '__main__' :
    # 입력 받은 정수 집합 S에 삽입 및 정렬
    for count in range(L):
        index = idx.split()
        S.append(int(index[count]))
        S.sort()
    
    # n 입력
    n = int(input())
    i = 0
    
    # 집합 S와 n 비교
    for i, compare in enumerate(S):
      
        # n이 집합 s의 원소와 같다면, 좋은 구간은 없다.
        if compare == n:
            print(answer)
            break
        
        # 제한 : n <= 집합 S에서 가장 큰 정수
        if compare > n:
            break
    
    # n이 집합 S의 원소 사이에 있을 때 == 좋은 구간이 존재할 때
    if i != 0:
        if S[i] != n :
            # S[i-1] < n < S[i]인 경우
            if (n - S[i-1]) == 1:
                print(1*(S[i]-n-1))
            else :
                print((n-S[i-1])*(S[i]-n)-1)
                
    # 1 <= n < S[0] 인 경우
    if S[0] > n :
        if n == 1:
            print(1*(S[0]-n)-1)
        else :
            print(n*(S[0]-n)-1)

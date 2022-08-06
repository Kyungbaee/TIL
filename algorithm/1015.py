"""
P[0], P[1], ...., P[N-1]은 0부터 N-1까지(포함)의 수를 한 번씩 포함하고 있는 수열이다. 
수열 P를 길이가 N인 배열 A에 적용하면 길이가 N인 배열 B가 된다. 적용하는 방법은 B[P[i]] = A[i]이다.

배열 A가 주어졌을 때, 수열 P를 적용한 결과가 비내림차순이 되는 수열을 찾는 프로그램을 작성하시오. 
비내림차순이란, 각각의 원소가 바로 앞에 있는 원소보다 크거나 같을 경우를 말한다. 만약 그러한 수열이 여러개라면 사전순으로 앞서는 것을 출력한다.
"""

# 배열 A의 크기 N 입력, ex) 3
N = int(input())

# 배열 A의 원소 입력, ex) A = 2 3 1
A = list(map(int, input().split()))

# 배열 A를 정렬한 배열 B, ex) B = 1 2 3
B = A.copy()
B.sort()

# 수열 p
p = list()

if __name__ == '__main__':
    for i in range(N):
        # 정렬된 배열 B에 A[i] 원소가 있으면, 위치 반환
        # ex) A[0] = 2, B.index(2) = 1 따라서 catch = 1 
        # B[P[i]] = A[i] 이므로 곧 catch가 P[i]이다.
        catch = B.index(A[i])
        
        # catch가 마지막 원소인 경우
        if (catch < N-1):
            # 다음 원소와 같지 않을 때
            if (B[catch] != B[catch+1]):
                p.append(B.index(A[i]))
            # 다음 원소와 같다면, 사전순으로 넣기
            elif (B[catch] == B[catch+1]):
                p.append(B.index(A[i]))
                B[catch] = -1
        # catch가 마지막 원소가 아닌 경우
        elif ~(catch < N-1):
            p.append(B.index(A[i]))
    
    # list p 문자열로 합치기
    answer = " ".join(str(value) for value in p)
    print(answer)

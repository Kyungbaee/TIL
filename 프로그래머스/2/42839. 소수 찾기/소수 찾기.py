from itertools import permutations

## 소수 찾기 함수
def prime_number(num):
    if num < 2: return False
    for div in range(2,int(num**(1/2))+1): 
        if num % div == 0: return False
    return True
        

def solution(numbers):
    ## numbers → List 형태로 변환
    ## 정답을 담을 set 생성
    numbers, answer = [num for num in numbers], set()
    
    for l in range(1,len(numbers)+1):
        ## 모든 경우의 수
        for combi in list(permutations(numbers,l)):
            combi = ''.join(combi)
            ## 앞이 0인 경우 제외
            if combi[0] == '0': combi = combi[1:]
            if combi and prime_number(int(combi)): answer.add(int(combi))
    return len(answer)
        
        
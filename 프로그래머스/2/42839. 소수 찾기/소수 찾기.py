from itertools import permutations

def prime_number(num):
    if num < 2: return False
    for div in range(2,int(num**(1/2))+1): 
        if num % div == 0: return False
    return True
        

def solution(numbers):
    numbers, answer = [num for num in numbers], set()
    
    for l in range(1,len(numbers)+1):
        for combi in list(permutations(numbers,l)):
            combi = ''.join(combi)
            if combi[0] == '0': combi = combi[1:]
            if combi and prime_number(int(combi)): answer.add(int(combi))
    return len(answer)
        
        
def solution(numbers):
    return str(int(''.join(sorted(map(str,numbers),key=lambda x:x*3,reverse=True))))
    
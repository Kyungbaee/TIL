def grading(case, answers):
    choice = []
    ## 수포자별 정답지
    if case == 1: choice = [1,2,3,4,5]
    if case == 2: choice = [2,1,2,3,2,4,2,5]
    if case == 3: choice = [3,3,1,1,2,2,4,4,5,5]
    
    ## 채점 후 점수 반환
    answers = [1 if answers[idx]==choice[idx%len(choice)] else 0 for idx in range(len(answers))]
    return sum(answers)

def solution(answers):
    case_1, case_2, case_3 = grading(1, answers), grading(2, answers), grading(3, answers)
    
    ## 최고 득점이 같다면, 번호 순으로 정렬
    max_score = max([case_1, case_2, case_3])
    answer = list(filter(lambda x: x[1]==max_score, [(1,case_1),(2,case_2),(3,case_3)]))
    return list(map(lambda x:x[0], answer))
    
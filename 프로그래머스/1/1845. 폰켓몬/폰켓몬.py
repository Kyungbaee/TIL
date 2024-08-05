def solution(nums):
    max_category, half_N = set(nums).__len__(), len(nums)/2
    if half_N >= max_category : return max_category
    if half_N < max_category : return half_N
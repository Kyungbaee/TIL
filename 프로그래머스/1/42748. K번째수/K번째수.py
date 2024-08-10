def solution(array, commands):
    return [sorted(array[com[0]-1:com[1]])[com[2]-1] for com in commands]
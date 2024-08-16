
def solution(brown, yellow):
    for w in range(yellow,0,-1):
        if yellow % w == 0 and brown == (w*2+(yellow//w)*2+4):
            return [w+2, (yellow//w)+2]
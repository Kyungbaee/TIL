while(True):
    nums = sorted(list(map(int, input().split())))
    x, y, z = nums

    if x==0 and y==0 and z==0:
        break
    elif z>= (y+x):
        print("Invalid")
    elif x==y==z:
        print("Equilateral")
    elif x==y or y==z or x==z:
        print("Isosceles")
    else:
        print("Scalene")
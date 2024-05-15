T = int(input())

for case in range(T):
    hstring = list(input())
    size = len(hstring)//2
    if hstring[:size]==hstring[-size:]:
        print(f"#{case+1} YES")
    else:
        print(f"#{case + 1} NO")
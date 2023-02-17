from sys import stdin
from queue import PriorityQueue

if __name__ == "__main__":
    N = int(stdin.readline())

    card_q = PriorityQueue()
    for _ in range(N):
        card_q.put(int(stdin.readline()))

    result_list = []
    while(True):
        if card_q.empty():
            break
        
        A = card_q.get()

        if card_q.empty():
            break

        B = card_q.get()

        result_list.append(A+B)
        card_q.put(A+B)
    
    print(sum(result_list))
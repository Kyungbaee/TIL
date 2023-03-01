from sys import stdin

class node():
    def __init__(self, num, next=None):
        self.num = num
        self.next = next

if __name__ == "__main__":
    N, K = map(int, stdin.readline().split())
    head = node(1)
    for num in range(2,N+1):
        cur = head
        while(cur.next != None):
            cur = cur.next
        cur.next = node(num)

        if num == N:
            cur.next.next = head
    
    cur, cnt, answer = head, 0, []
    if K == 1:
        for _ in range(N):
            answer.append(cur.num)
            cur = cur.next
    else:
        while(cnt < N):
            for _ in range(K-2):
                cur = cur.next
            answer.append(cur.next.num)
            cur.next = cur.next.next
            cur = cur.next
            cnt += 1

    print("<", end="")
    for num in answer:
        if num == answer[-1]:
            print(num, end="")
        else:
            print(num, end=", ")
    print(">")
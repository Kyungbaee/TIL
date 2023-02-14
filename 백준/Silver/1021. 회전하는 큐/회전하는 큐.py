from sys import stdin

# 링크드리스트에 사용할 원소
class Node:
    def __init__(self,data,next=None):
        self.data = data
        self.next = next

# 링크드리스트 및 기능
class LinkedList:
    def __init__(self):
        self.node_cnt = 0
        self.head = None

	## 첫 번째 원소 삽입
    def add_first(self, data):
        pointer = self.head
        self.head = Node(data, pointer)
        self.node_cnt += 1

	## 이후 원소들 삽입
    def add_last(self, data):
        pointer = self.head
        while pointer.next:
            pointer = pointer.next

        pointer.next = Node(data, None)
        self.node_cnt += 1

	## 해당 값을 가지고 있는 원소 찾기
    def find(self, data):
        pointer = self.head
        cnt = 0
        while pointer.data != data:
            pointer = pointer.next
            cnt += 1
        return cnt

	## 첫 번째, 원소 제거
    def pop(self):
        self.head = self.head.next
        self.node_cnt -= 1

	## 두 번째, 왼쪽 이동 
    def Left(self,L):
        for _ in range(L):
            node = self.head
            while node.next:
                node = node.next
            node.next = self.head
            self.head = self.head.next
            node.next.next = None

	## 세 번째, 오른쪽 이동
    def Right(self,R):
        for _ in range(R):
            node = self.head
            while node.next.next:
                node = node.next
            node.next.next = self.head
            self.head = node.next
            node.next = None



if __name__ == "__main__":
	## 큐의 크기 N, 뽑으려 하는 수 M개
    ## N <= 50, M <= N
    N, M = map(int, stdin.readline().split())
    ll = LinkedList()

    result = 0
	
    for i in range(1,N+1):
        if i == 1:
            ll.add_first(i)
        else:
            ll.add_last(i)

    ## 뽑고자 하는 수
    num = list(map(int, stdin.readline().split()))

    for i in num:
        move = ll.find(i)

        if (move == 0):
            ll.pop()
        else:
            if(move <= ll.node_cnt-move):
                result += move
                ll.Left(move)
                ll.pop()
            else:
                result += ll.node_cnt-move     
                ll.Right(ll.node_cnt-move)
                ll.pop()                          
    print(result)

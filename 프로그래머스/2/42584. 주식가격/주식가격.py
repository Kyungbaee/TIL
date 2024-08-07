def solution(prices):
    answer = []
    for i in range(len(prices)):
        cnt = 1
        for j in range(i+1,len(prices)):
            if prices[i] <= prices[j]:
                if j == len(prices)-1:
                    answer.append(cnt)
                    break
                cnt += 1
            elif prices[i] > prices[j]:
                answer.append(cnt)
                break
    answer.append(0)
    return answer
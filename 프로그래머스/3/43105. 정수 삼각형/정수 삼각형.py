from copy import deepcopy
def solution(triangle):
    dp = deepcopy(triangle)
    
    for i in range(len(triangle)-1):
        length = len(triangle[i])
        for j in range(length):
            dp[i+1][j] = max(dp[i][j] + triangle[i+1][j], dp[i+1][j])
            dp[i+1][j+1] = max(dp[i][j] + triangle[i+1][j+1], dp[i+1][j+1])
    
    return max(dp[-1])
#include <iostream>

using namespace std;

int dp[100001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;
    dp[1] = -1;
    dp[2] = 1;
    dp[5] = 1;


    for(int i=1; i<n; i++)
    {
        if(dp[i] != -1)
        {
            if(i+2 <= n) 
            {
                if(dp[i+2] <= 0) dp[i+2] = dp[i]+1;
                else dp[i+2] = min(dp[i]+1, dp[i+2]);
            }
            if(i+5 <= n) 
            {
                if(dp[i+5] <= 0) dp[i+5] = dp[i]+1;
                else dp[i+5] = min(dp[i]+1, dp[i+5]);
            }
        }
        else
        {
            if(i+2 <= n && dp[i+2]==0) dp[i+2] = -1;
            if(i+5 <= n && dp[i+5]==0) dp[i+5] = -1;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
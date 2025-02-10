#include <iostream>

using namespace std;

int coins[101];
int dp[100001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }

    for(int i=1; i<k; i++)
    {
        if(dp[i])
        {
            for(int j=0; j<n; j++)
            {
                if(i+coins[j] <= k)
                {
                    if(dp[i+coins[j]] == 0) dp[i+coins[j]] = dp[i]+1;
                    else dp[i+coins[j]] = min(dp[i]+1, dp[i+coins[j]]);
                }
            }
        }
    }
    
    if(dp[k]) cout << dp[k];
    else cout << "-1";

    return 0;
}
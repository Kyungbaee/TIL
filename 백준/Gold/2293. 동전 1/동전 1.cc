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
        cin >> coins[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    cout << dp[k];

    return 0;
}
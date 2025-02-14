#include <iostream>
#include <string>

using namespace std;

int dp[101][101][101];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    string a, b, c;
    cin >> a >> b >> c;

    for(int i=1; i<=a.length(); i++)
    {
        for(int j=1; j<=b.length(); j++)
        {
            for(int k=1; k<=c.length(); k++)
            {
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max(max(max(dp[i][j-1][k-1], dp[i-1][j][k-1]), max(dp[i][j-1][k], dp[i-1][j][k])), max(dp[i][j][k-1], dp[i-1][j-1][k]));
            }
        }
    }

    cout << dp[a.length()][b.length()][c.length()];
    return 0;
}
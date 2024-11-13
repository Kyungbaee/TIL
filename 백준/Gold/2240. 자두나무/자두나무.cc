#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][31][3];
int tree[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t,w;
    cin >> t >> w;
    
    for(int i=1; i<=t; i++)
        cin >> tree[i];
    
    for(int i=1; i<=t; i++){
        dp[i][0][1] = dp[i-1][0][1] + (tree[i]==1 ? 1:0);
        
        for(int j=1; j<=w; j++){
            if(i<j) break;
            
            if(tree[i]==1){
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]) + 1;
                dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][1]);
            }
            if(tree[i]==2){
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]);
                dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][1]) + 1;
            }
        }
    }
    int answer = 0;
    for(int j=1; j<=w; j++){
        answer = max({answer, dp[t][w][1], dp[t][w][2]});
    }
    cout << answer;
}
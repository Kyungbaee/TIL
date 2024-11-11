#include <iostream>
using namespace std;

int dp[1000001];
int route[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt=0;
    cin >> n;
    dp[1] = 0;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+1;
        if (i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
        if (i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
    }
    cout << dp[n] << '\n';
    cout << n << ' ';
    
    while(n>1){
        int min_n = n-1;
        route[n] = dp[n-1];
        
        if ((n%3==0)&&(route[n] > dp[n/3])){
            min_n = n/3;
            route[n] = dp[n/3];
        }
        if ((n%2==0)&&(route[n] > dp[n/2])){
            min_n = n/2;
            route[n] = dp[n/2];
        }
        cout << min_n << ' ';
        n = min_n;
    }
}
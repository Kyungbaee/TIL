#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt=0;
    cin >> n;
    dp[1] = 0;
    
    // 2부터 n까지 채우기
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+1;    /// 최소 연산 방법이 -1 이라고 가정할 때
        if (i%3==0) dp[i] = min(dp[i], dp[i/3]+1); /// 최소 연산 방법이 나누기 3 이라고 가정할 때
        if (i%2==0) dp[i] = min(dp[i], dp[i/2]+1); /// 최소 연산 방법이 나누기 2 이라고 가정할 때
    }
    cout << dp[n] << '\n';
    cout << n << ' ';
    
    // n부터 2까지 내려가기
    while(n>1){
        int min_n = n-1;    /// 최소 연산 방법이 -1 이라고 가정할 때
        int route = dp[n-1]; // 최소값 경로 저장
        
        /// 최소 연산 방법이 나누기 3 이라고 가정할 때, 업데이트
        if ((n%3==0)&&(route > dp[n/3])){
            min_n = n/3;
            route = dp[n/3];
        }
        /// 최소 연산 방법이 나누기 2 이라고 가정할 때, 업데이트
        if ((n%2==0)&&(route > dp[n/2])){
            min_n = n/2;
            route = dp[n/2];
        }
        cout << min_n << ' ';
        n = min_n;
    }
}
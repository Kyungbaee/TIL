#include <iostream>
#include <algorithm>

using namespace std;

int A[1002];
int dp[1002];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int a;
    cin >> a;

    for(int i=1; i<=a; i++) cin >> A[i];

    for(int i=1; i<=a; i++)
    {
        int mx = 0;
        for(int j=0; j<i; j++)
        {
            if(A[i]>A[j])
                mx = max(dp[j], mx);
        }
        dp[i] = mx+1;
    }

    cout << *max_element(dp+1, dp+(a+1));
    return 0;
}
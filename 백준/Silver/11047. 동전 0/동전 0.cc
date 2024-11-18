#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K,cnt=0;
    int nums[11];
    
    cin >> N >> K;
    
    for(int i=1; i<=N; i++)
    cin >> nums[i];
  
    for(int i=N; i>=1; i--){
        if(nums[i]<= K){
            cnt += K/nums[i];
            K -= nums[i] * (K/nums[i]);
        }
    }
    
    cout << cnt;
    
    return 0;
}
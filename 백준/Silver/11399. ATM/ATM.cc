#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,T=0;
    int nums[1001];
    
    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> nums[i];
    sort(nums, nums+N, less<int>());
    
    for(int i=0; i<N; i++)
        T += nums[i]*(N-i);
        
    cout << T;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    long long S = 0;
    int nums[51];
    
    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> nums[i];
    sort(nums, nums+N, less<int>());
    
    int i=0;
    
    for(i=0; i<N; i++){
        if(i==N-1)
            S += nums[i];
        else if(nums[i]<0 && nums[i+1]<0){
            S += (nums[i]*nums[i+1]);
            i++;
        }
        else if(nums[i]<0 && nums[i+1]==0)
            i++;
        else if(nums[i]>=0 && nums[i+1]>=0)
            break;
        else
            S += nums[i];
    }

    for (int j=N-1; j>=i; j--){

        if(j==0 && nums[j]>0)
            S += nums[j];
        else if (nums[j]>1 && nums[j-1]>1){
            S += (nums[j]*nums[j-1]);
            j--;
        }
        else if (nums[j]<=0 && nums[j-1]<=0)
            break;
        else
            S += nums[j];
    }

    if(N==1) cout << nums[0];
    else cout << S;
    return 0;
}
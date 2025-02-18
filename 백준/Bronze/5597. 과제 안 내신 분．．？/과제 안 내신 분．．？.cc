#include <iostream>

using namespace std;

int nums[31];

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int rp=28;
    
    while(rp--)
    {
        int n;
        cin >> n;
        
        nums[n]=1;
    }
    
    for(int i=1; i<31; i++)
    {
       if(!nums[i]) cout << i << endl;
    }
    
    return 0;
}
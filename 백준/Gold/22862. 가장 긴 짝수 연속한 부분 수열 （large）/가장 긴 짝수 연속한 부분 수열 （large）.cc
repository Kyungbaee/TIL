#include <iostream>

using namespace std;

int nums[1'000'001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) cin >> nums[i];

    int answer = 0;

    int st = 0, ed = 0, cnt = 0; 
    while(st < n)
    {
        while((k || !(nums[ed]%2)) && ed<n)
        {
            if(nums[ed]%2) k--;
            else cnt++;
            ed++;
        }

        answer = max(answer, cnt);

        if(nums[st]%2) k++;
        else cnt--;
        st++;
    }

    cout << answer;
    return 0;
}
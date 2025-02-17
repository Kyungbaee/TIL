#include <iostream>
#include <algorithm>

using namespace std;

int nums[100'001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums, nums+n, less<int>());

    int left=0, right=n-1;
    long long answer = 2'000'000'000;
    int a_left=0, a_right=0;

    while(left<right)
    {
        int sum_nums = nums[left] + nums[right];

        if(abs(answer) > abs(sum_nums))
        {
            answer = sum_nums;
            a_left = left;
            a_right = right;
        }

        if(sum_nums > 0) right--;
        if(sum_nums < 0) left++;
        if(sum_nums == 0) break;
    }

    cout << nums[a_left] << " " << nums[a_right];
    return 0;
}
#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    long long n, k;
    cin >> n >> k;

    long long st=0, ed=n;
    while(st < ed)
    {
        long long mid = (st+ed)/2;
        long long paper = (mid+1)*(n-mid+1);
        if(paper >= k) ed = mid;
        else st = mid+1;
    }

    if((st+1)*(n-st+1) == k) cout << "YES";
    else cout << "NO";
    return 0;
}
#include <iostream>

using namespace std;

int check[100'001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> check[i];
    
    unsigned long long st=0, ed=1e19;
    while(st < ed)
    {
        unsigned long long mid = (st+ed)/2, cnt=0;
        for(int i=0; i<n; i++)
            cnt += mid/check[i];
        if(cnt >= m) ed = mid;
        else st = mid+1;

    }

    cout << st;
    return 0;
}
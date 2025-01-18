#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, num;
    cin >> n;

    priority_queue<int> pq;

    for(int i=0; i<n*n; i++)
    {
        cin >> num;
        if(pq.size()>=n)
        {
            if(pq.top()>-num)
            {
                pq.pop();
                pq.push(-num);
            }
        }
        else pq.push(-num);
    }

    cout << pq.top() * -1 << " ";

    // vector<int> v;

    // for(int i=0; i<n*n; i++)
    // {
    //     cin >> num;
    //     v.push_back(num);
    // }

    // sort(v.begin(), v.end(), [](int i, int j){ return j<i; });

    // cout << v[n-1];

    return 0;
}
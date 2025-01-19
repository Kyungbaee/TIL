#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    priority_queue<pair<int, int>> pq;

    int n, num;
    cin >> n;

    while(n--)
    {
        cin >> num;
        if(num == 0)
        {
            if(pq.empty()) cout << "0\n";
            else
            {
                cout << pq.top().second * -1 << "\n";
                pq.pop();
            }
        }
        else
        {
            if(num > 0) pq.push(make_pair(-num, -num));
            else pq.push(make_pair(num, -num));
        }
    }
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;

int visited[200001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, k;
    cin >> n >> k;

    if(n==k)
    {
        cout << 0;
        return 0;
    }

    deque<pair<int, int>> q;
    q.push_back(make_pair(1,n));
    visited[n]=1;

    while(!q.empty())
    {
        int t = q.front().first, nxt = q.front().second;
        q.pop_front();

        if(nxt == k)
            break;

        for(int mv : {nxt, -1, 1})
        {
            int next = nxt+mv, next_t = t;
            if (mv != nxt) next_t++;

            if(next >= 0 && next<= 200'000 && !visited[next])
            {
                if (mv != nxt) q.push_back(make_pair(next_t, next));
                else q.push_front(make_pair(next_t, next));
                visited[next] = next_t;
            }
        }
    }

    cout << visited[k]-1;
    return 0;
}
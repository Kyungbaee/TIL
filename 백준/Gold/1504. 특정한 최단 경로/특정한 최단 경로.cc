#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<pair<int, int>> adj[801];
int d[801];

const int inf = 0x3f3f3f3f;
int N, E;

ll calc(int st, int end)
{
    fill(d, d+N+1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[st]=0;
    pq.push({d[st], st});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(d[cur.second] != cur.first) continue;

        for(auto next : adj[cur.second])
        {
            if(d[next.second] <= d[cur.second]+next.first) continue;
            d[next.second] = d[cur.second]+next.first;
            pq.push({d[next.second], next.second});
        }
    }

    return d[end];
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> N >> E;

    while(E--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int v1, v2;
    cin >> v1 >> v2;

    ll ans1 = calc(1, v1) + calc(v1, v2) + calc(v2, N);
    ll ans2 = calc(1, v2) + calc(v2, v1) + calc(v1, N);
    ll answer = min(ans1, ans2);
    if(answer >= inf) answer = -1;

    cout << answer;

    return 0;
}
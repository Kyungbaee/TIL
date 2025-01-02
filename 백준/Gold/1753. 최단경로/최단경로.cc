#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<pair<int, int>> adj[20001];
const int inf = 0x7f7f7f7f;
int d[20001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int V, E, K;
    cin >> V >> E >> K;

    fill(d, d+V+1, inf);

    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w,v});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[K]=0;
    pq.push({d[K], K});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(d[cur.second] != cur.first) continue;
        for(auto nxt : adj[cur.second])
        {
            if(d[nxt.second] <= d[cur.second]+nxt.first) continue;
            d[nxt.second] = d[cur.second]+nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }

    for(int i=1; i<=V; i++)
    {
        if(d[i]==inf) cout << "INF\n";
        else cout << d[i] << "\n";
    }
    
    return 0;
}
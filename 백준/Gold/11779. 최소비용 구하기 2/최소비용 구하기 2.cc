#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> adj[1001];
int d[1001];
int pre[1001];
const int inf = 0x7f7f7f7f;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    fill(d, d+n+1, inf);

    while(m--)
    {
        int st, end, w;
        cin >> st >> end >> w;

        adj[st].push_back({w, end});
    }

    int st, end;
    cin >> st >> end;

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
            pre[next.second] = cur.second;
        }
    }

    cout << d[end] << "\n";

    vector<int> path;

    while(end != st)
    {
        path.push_back(end);
        end = pre[end];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";
    for(int next : path) cout << next << " ";
    return 0;
}
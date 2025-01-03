#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> adj[1001];
int d[1001];
int r[1001];

const int inf = 0x7f7f7f7f;
int N, M, X;

void calc(int i, int X)
{    
    fill(d, d+N+1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[i]=0;
    pq.push({d[i], i});

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

    if(i != X) r[i] += d[X];
    else 
        for(int i=1; i<=N; i++) r[i] += d[i];
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> N >> M >> X;

    while(M--)
    {
        int st, end, t;
        cin >> st >> end >> t;

        adj[st].push_back({t, end});
    }

    for(int i=1; i<=N; i++)
        calc(i, X);


    cout << *max_element(r, r+N+1);
    return 0;
}
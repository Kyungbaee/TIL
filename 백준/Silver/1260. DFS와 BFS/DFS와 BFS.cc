#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> adj[1001];
bool visited[1001];

void dfs(int v)
{
    visited[v] = true;
    cout << v << " ";
    for(int next : adj[v])
    {
        if(!visited[next]) dfs(next);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty())
    {
        int i = q.front();
        cout << i << " ";
        q.pop();

        for(int next : adj[i])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m, v;
    cin >> n >> m >> v;

    while(m--)
    {
        int p, c;
        cin >> p >> c;

        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    for(int i=1; i<=n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << "\n";
    fill(visited+1, visited+n+1, false);
    bfs(v);

    return 0;
}
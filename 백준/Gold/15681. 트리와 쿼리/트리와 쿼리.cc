#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int length[100001];
bool visited[100001];

int dfs(int cur)
{
    visited[cur]=true;

    for(int next : adj[cur])
    {
        if(visited[next]) continue;
        length[cur] += dfs(next);
    }
    length[cur]++;
    return length[cur];
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, r, q;
    cin >> n >> r >> q;

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r);

    while(q--)
    {
        int root, ans=0;
        cin >> root;
        cout << length[root] << "\n";
    }

    return 0;
}
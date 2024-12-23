#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
int cnt[32001];

void solve(int n)
{
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(cnt[i]==0) q.push(i);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int next : adj[cur])
        {
            cnt[next]--;
            if(cnt[next]==0) q.push(next);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        cnt[b]++;
    }

    solve(n);
    return 0;
}
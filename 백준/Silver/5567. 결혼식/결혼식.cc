#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
int visited[501];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n]=1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int next : adj[cur])
        {
            if(!visited[next]){
                visited[next] = visited[cur]+1;
                q.push(next);
            }
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
        adj[b].push_back(a);
    }

    bfs(1);

    int ans=0;
    for(int i=1; i<501; i++)
    {
        if(visited[i]>1 && visited[i]<=3) ans++;
    }

    cout << ans;

    return 0;
}
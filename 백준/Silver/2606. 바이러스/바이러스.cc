#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> adj[101];
bool visited[101];
int ans;

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : adj[cur])
        {
            if(!visited[next])
            {
                visited[next]=true;
                q.push(next);
                ans++;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int com, cnt;
    cin >> com >> cnt;

    while(cnt--)
    {
        int p, c;
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    bfs(1);
    cout << ans;
    return 0;
}
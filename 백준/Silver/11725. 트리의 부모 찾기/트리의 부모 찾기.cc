#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
int visited[100001];

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1]=1;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : adj[cur])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = cur;
            }
        }

    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int L, R;
        cin >> L >> R;

        adj[L].push_back(R);
        adj[R].push_back(L);
    }

    bfs();

    for(int i=2; i<=n; i++)
       cout << visited[i] << "\n";

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501];
bool visited[501], isTree;
int cnt=0, test_case=1;

void dfs(int n, int parent)
{
    visited[n]=true;

    for(int next : adj[n])
    {
        if(next == parent) continue;

        if(visited[next])
        {
            isTree = false;
            continue;
        }
        dfs(next, n);
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음


    while(true)
    {
        cnt=0;

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            adj[i].clear();
        fill(visited+1, visited+n+1, false);

        if(n==0 && m==0) break;

        while(m--)
        {
            int v1, v2;
            cin >> v1 >> v2;

            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        for(int i=1; i<=n; i++)
        {
            if(visited[i]) continue;
            isTree = true;
            dfs(i, 0);
            cnt += isTree;
        }

        cout << "Case " << test_case << ":";
        if(cnt==0) cout << " No trees.\n";
        if(cnt==1) cout << " There is one tree.\n";
        if(cnt>1) cout << " A forest of " << cnt << " trees.\n";
        
        test_case++;
    }

    return 0;
}
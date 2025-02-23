#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visited[10001];
int hacking[10001];
vector<int> network[10001];

int bfs(int st)
{
    queue<int> q;
    q.push(st);

    fill(visited, visited+10001, 0);
    visited[st]=1;

    int cnt=1;

    while(!q.empty())
    {
        int nxt = q.front();
        q.pop();

        for(int next : network[nxt])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next]=1;
                cnt++;
            }
        }
    }

    return cnt;
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
        network[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        hacking[i] = bfs(i);
    
    int max_cnt = *max_element(hacking, hacking+n+1);   // max_element 범위 주의..

    for(int i=1; i<=n; i++)
        if(hacking[i] == max_cnt)
            cout << i << " ";
    
    return 0;
}
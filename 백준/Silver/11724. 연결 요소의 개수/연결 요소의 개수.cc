#include <iostream>
#include <vector>

using namespace std;
vector<int> v[1001];
bool visited[1001];

void dfs(int n){
    visited[n] = true;
    for(int next : v[n])
    {
        if(!visited[next])
            dfs(next);
    }

}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m, ans=0;
    cin >> n >> m;

    while(m--)
    {
        int p, c;
        cin >> p >> c;
        v[p].push_back(c);
        v[c].push_back(p);
    }
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans++;
            dfs(i);
        }
    }

    cout << ans;
    return 0;
}
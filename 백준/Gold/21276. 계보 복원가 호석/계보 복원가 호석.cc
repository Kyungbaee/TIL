#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
vector<string> roots;
vector<int> ch[1001];
int cnt[1001];
map<string, int> name_to_num;
string num_to_name[1001];

void solve(int n)
{
    queue<int> q;
    int root_cnt = 0;

    for(int i=0; i<n; i++)
        if(cnt[i]==0){
            q.push(i);
            root_cnt++;
            roots.push_back(num_to_name[i]);
        }
    
    sort(roots.begin(), roots.end());

    cout << root_cnt << "\n";
    for(string root : roots) cout << root << " ";
    cout << "\n";

    // indegree가 1 많은 후손(자녀)들의 정보를 배열 ch에 저장
    for(int i=0; i<n; i++) {
        sort(adj[i].begin(), adj[i].end());
        for(int c : adj[i])
        if(cnt[c] - cnt[i] == 1) ch[i].push_back(c);
    }

    for(int i=0; i<n; i++)
    {
        cout << num_to_name[i] << " " << ch[i].size() << " ";
        for(int child : ch[i]) cout << num_to_name[child] << " ";
        cout << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n;

    for(int i=0; i<n; i++){
        string name;
        cin >> name;

        num_to_name[i] = name;
    }
    sort(num_to_name, num_to_name+n);

    for(int i=0; i<n; i++)
        name_to_num[num_to_name[i]] = i;

    cin >> m;

    while(m--)
    {
        string a, b;
        cin >> a >> b;

        adj[name_to_num[b]].push_back(name_to_num[a]);
        cnt[name_to_num[a]]++;
    }

    solve(n);
    return 0;
}
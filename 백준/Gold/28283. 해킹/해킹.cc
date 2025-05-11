#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int money[500001];
int security[500001];
int chk[500001];
vector<int> network[500001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n,m,x,y;
    cin >> n >> m >> x >> y;

    for(int i=1; i<=n; i++) cin >> money[i];

    while(m--){
        int s, e;
        cin >> s >> e ;
        network[s].push_back(e);
        network[e].push_back(s);
    }

    queue<int> q;

    for(int i=1; i<=y; i++) {
        cin >> security[i];
        chk[security[i]] = 1;
        q.push(security[i]);
    }

    while(!q.empty()){
        int pc = q.front(); q.pop();

        for(int nxt : network[pc]){
            if(!chk[nxt]){
                q.push(nxt);
                chk[nxt] = chk[pc]+1;
            }
        }
    }

    long long maximum = 0;
    priority_queue<long long> pq;
    for(int i=1; i<=n; i++) {
        if(!chk[i] && money[i]){
            cout << "-1";
            return 0;
        }
        pq.push(1LL * (chk[i]-1) * money[i]);
    }

    while(x--){
        maximum += pq.top();
        pq.pop();
    }
    cout << maximum;
    return 0;
}
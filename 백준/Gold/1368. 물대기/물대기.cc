#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int chk[301];
vector<pair<int, int>> non[301];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int ,int, int>>> pq;

    for(int i=1; i<=n; i++) {
        int w;
        cin >> w;
        pq.push({w, i, 0});
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int w;
            cin >> w;
            if(w) non[i].push_back({w, j});
        }
    }

    int dig=0, connect=0, totalCost = 0;

    while((dig+connect) < n){
        int cost, b, type;
        tie(cost, b, type) = pq.top(); pq.pop();

        if(chk[b]) continue;
        chk[b] = 1;

        if(type) connect++;
        else dig++;

        totalCost += cost;

        for(auto nxt : non[b]){
            if(!chk[nxt.second]) pq.push({nxt.first, nxt.second, 1});
        }
    }

    cout << totalCost;
    
    return 0;
}
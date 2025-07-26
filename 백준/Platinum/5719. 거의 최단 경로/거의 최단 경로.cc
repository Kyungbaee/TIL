#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> v[501];

int table[501];
vector<int> route[501];
bool Destroy[501][501];
int x, y, INF = 1e9+10;

void removeParent(int target, int st, int ed){
    if(Destroy[st][ed]) return;
    Destroy[st][ed] = true;
    if(st == target) return;
    for(int r : route[st]) removeParent(target, r, st);
}

void search(int n, int m, bool trigger){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    fill(table, table+x+1, INF);
    table[n] = 0;
    pq.push(make_pair(table[n], n));

    while(!pq.empty()){
        auto [distance, st] = pq.top();
        pq.pop();

        for(auto [cur, next, nDistance] : v[st]) {
            if(!Destroy[cur][next]){
                // 경로 갱신
                if(table[next] > distance+nDistance) {
                    table[next] = distance+nDistance;
                    route[next].clear();
                    route[next].push_back(cur);
                    pq.push(make_pair(table[next], next));
                }
                // 최단 경로가 같은 경우
                else if(table[next] == distance+nDistance){
                    route[next].push_back(cur);
                }
            }
        }
    }

    if(trigger){
        if(table[m]==INF) cout << -1 << "\n";
        else cout << table[m] << "\n";
    }

    for(int r: route[m]) {
        removeParent(n, r, m);
    }
    route[m].clear();
    table[m]=INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> x >> y;

        if(x==0 && y==0) break;

        int n, m;
        cin >> n >> m;
        for(int i=0; i<501; i++) fill(Destroy[i], Destroy[i]+x+1, false);
        while(y--){
            int st, ed, distance;
            cin >> st >> ed >> distance;

            v[st].push_back(make_tuple(st, ed, distance));
        }

        search(n, m, false);
        search(n, m, true);
        for(int i=0; i<501; i++) {
            route[i].clear();
            v[i].clear();
        }
    }


    return 0;
}
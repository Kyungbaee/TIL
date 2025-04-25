#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[1001];
int depth[1001];
vector<int> v[1001];
queue<int> q;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        indegree[b]++;
    }

    for(int d=1; d<=n; d++){

        for(int i=1; i<=n; i++){
            if(indegree[i]==0 && depth[i]==0) {
                q.push(i);
                depth[i] = d;
            }
        }
        
        while(!q.empty()){
            int idx = q.front();
            q.pop();

            for(int cIdx : v[idx]) indegree[cIdx]--;
        }
    }

    for(int i=1; i<=n; i++) cout << depth[i] << " ";
    return 0;
}
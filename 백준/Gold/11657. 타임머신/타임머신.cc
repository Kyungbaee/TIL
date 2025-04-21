#include <iostream>
#include <vector>

using namespace std;

struct info {
    int x, y;
    long long z;
};

int inf = 1e9;
long long node[501];

vector<info> value;

bool search(int n, int m){

    for(int i=0; i<n; i++)
    {
        for(info v : value)
        {
            int cur = v.x, next = v.y;
            long long cost = v.z;
            
            if(node[cur] != inf && (node[next] > node[cur] + cost)){
                node[next] = node[cur]+cost;
                if (i == n-1) return true;
            }
        }
    }

    return false;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    fill(node+2, node+n+1, inf);

    for(int i=0; i<m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        value.push_back({a, b, c});
    }

    bool result = search(n, m);

    if (result) cout << "-1";
    else{
        for(int i=2; i<=n; i++){
            if(node[i] == inf) cout << "-1\n";
            else cout << node[i] << "\n";
        }
    }

    return 0;
}
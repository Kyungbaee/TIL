#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V[10001];
tuple<int, int, int> E[100001];

int getParent(int x){
    if(V[x] == x) return x;
    return V[x] = getParent(V[x]);
}

bool isSameParent(int x, int y){
    x = getParent(x), y = getParent(y);
    if(x == y) return 1;
    if(x < y) V[y] = x;
    else V[x] = y;
    return 0;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int v, e;
    cin >> v >> e;

    for(int i=1; i<=v; i++) V[i] = i;

    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        E[i] = {c, a, b};
    }

    sort(E, E+e);

    int cntE = 0, Cost = 0;

    for(auto data : E){
        int a, b, c;
        tie(c, a, b) = data;

        if(isSameParent(a, b)) continue;
        cntE++;
        Cost += c;

        if(cntE == (v-1)) break;
    }

    cout << Cost;

    return 0;
}
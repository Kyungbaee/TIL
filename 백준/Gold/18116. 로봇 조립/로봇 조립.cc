#include <iostream>

using namespace std;

int parent[1'000'001];
int cnt[1'000'001];

int getParent(int num){
    if(parent[num]==num) return num;
    return parent[num] = getParent(parent[num]);
}

void func_union(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a == b) return;

    if(a < b) {
        parent[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
    }
    else {
        parent[a] = b;
        cnt[b] += cnt[a];
        cnt[a] = 0;
    }
}

void func_find(int c){
    c = getParent(c);
    cout << cnt[c] << "\n";
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    for(int i=1; i<=1'000'000; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }

    int n;
    cin >> n;

    while(n--){
        char c;
        cin >> c;

        if(c=='I'){
            int a, b;
            cin >> a >> b;
            func_union(a, b);
        }
        else{
            int c;
            cin >> c;
            func_find(c);
        }
    }

    return 0;
}
#include <iostream>

using namespace std;

const int mx = 10 * 10000 + 1;
int nxt[mx][10];
bool chk[mx];

int root = 1;
int unused = 2;

int ctoi(char c){
    return c-'0';
}

int insert(string s){
    int cur = root;
    int idx = 0;
    for(auto c : s){
        if(nxt[cur][ctoi(c)] == -1){
            nxt[cur][ctoi(c)] = unused++;
        }
        else if(chk[nxt[cur][ctoi(c)]] || (idx == (s.length()-1)))
            return 1;

        cur = nxt[cur][ctoi(c)];
        idx++;
    }
    chk[cur] = true;
    return 0;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int t;
    cin >> t;

    while(t--){
        for(int i=0; i<mx; i++) fill(nxt[i], nxt[i]+10, -1);
        fill(chk, chk+mx, false);
        unused = 2;

        int n;
        cin >> n;

        int result = 0;

        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            
            result += insert(s);
        }
        if(result) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
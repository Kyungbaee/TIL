#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int route[101][101];
int d[101][101];
const int inf = 0x3f3f3f3f;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) d[i][j] = inf;
    for(int i=1; i<=n; i++) d[i][i] = 0;

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        d[a][b] = min(d[a][b], c);
        route[a][b] = b;
    }


    // 플로이드
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(d[i][j] >  d[i][k] + d[k][j]){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // 정점이 1000개면 시간초과 발생할 수 있음 (if문으로 대입연산 줄이기)
                    route[i][j] = route[i][k];
                }
            }


    // 최소 비용 출력
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(d[i][j]==inf) cout << "0 ";  // 예외 처리
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    // 경로 출력
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(d[i][j]==0 || d[i][j]==inf) {
                cout << "0" << "\n";  // 예외 처리
                continue;
            }
            
            vector<int> path;
            int st=i;

            while(st != j)
            {
                path.push_back(st);
                st = route[st][j];
            }
            path.push_back(j);

            cout << path.size() << " ";
            for(int nxt : path) cout << nxt << " ";
            cout << "\n";
        }
    }

    return 0;
}
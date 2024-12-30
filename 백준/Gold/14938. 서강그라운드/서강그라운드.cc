#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int d[101][101];
int item[101];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m, r;
    cin >> n >> m >> r;

    for(int i=1; i<=n; i++) {
        cin >> item[i];
        fill(d[i], d[i]+1+n, inf);
        d[i][i]=0;
    }

    while(r--)
    {
        int a, b, l;
        cin >> a >> b >> l;

        d[a][b] = min(d[a][b], l);
        d[b][a] = min(d[b][a], l);
    }

    // 플로이드
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k]+d[k][j])
                    d[i][j] = d[i][k]+d[k][j];
            }

    // 낙하 위치 + 최소 거리를 통한 파밍
    int maxItemCnt = 0;
    for(int i=1; i<=n; i++){
        int itemCnt=0;
        for(int j=1; j<=n; j++){
            if(d[i][j] <= m) itemCnt += item[j];
        }
        maxItemCnt = max(maxItemCnt, itemCnt);
    }
    cout << maxItemCnt;

    return 0;
}
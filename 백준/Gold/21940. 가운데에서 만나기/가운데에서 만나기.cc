#include <iostream>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;
int d[201][201];
int p[201];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        {
            fill(d[i], d[i]+1+n, inf);
            d[i][i]=0;
        }

    while(m--)
    {
        int a, b, t;
        cin >> a >> b >> t;

        d[a][b] = t;
    }

    int k;
    cin >> k;

    for(int i=0; i<k; i++)
        cin >> p[i];
    

    for(int h=1; h<=n; h++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j] = min(d[i][j], d[i][h]+d[h][j]);


    vector<int> ans_X;
    int ans_T=0x7f7f7f7f;
    for(int X=1; X<=n; X++)
    {
        int maxTime = 0;
        for(int i=0; i<k; i++)
            maxTime = max(maxTime, d[p[i]][X] + d[X][p[i]]);
        
        if(maxTime <= ans_T)
        {
            if(maxTime < ans_T)
            {
                ans_T = maxTime;
                ans_X.clear();
            }
            ans_X.push_back(X);
        }
    }

    for(int center : ans_X) cout << center << " ";
    
    return 0;
}
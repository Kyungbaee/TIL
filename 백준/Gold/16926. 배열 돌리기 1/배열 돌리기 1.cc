#include <iostream>

using namespace std;

int arr[301][301];
int move_arr[301][301];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m, r;
    cin >> n >> m >> r;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    int sqr_cnt = min((n+1)/2, (m+1)/2);

    while(r--)
    {
        for(int i=0; i<sqr_cnt; i++)
        {
            // 좌측
            for(int j=i; j<n-(i+1); j++)
                move_arr[j+1][i] = arr[j][i];

            // 하단
            for(int j=i; j<m-(i+1); j++)
                move_arr[n-(i+1)][j+1] = arr[n-(i+1)][j];

            // 우측
            for(int j=n-(i+1); j>i; j--)
                move_arr[j-1][m-(i+1)] = arr[j][m-(i+1)];

            // 상단
            for(int j=m-(i+1); j>i; j--)
                move_arr[i][j-1] = arr[i][j];

        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                arr[i][j] = move_arr[i][j];
        }    
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
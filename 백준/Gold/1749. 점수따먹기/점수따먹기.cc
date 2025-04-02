#include <iostream>

using namespace std;

long long game[201][201];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    long long n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> game[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i > 0) game[i][j] += game[i-1][j];
            if(j > 0) game[i][j] += game[i][j-1];
            if(i>0 && j>0) game[i][j] -= game[i-1][j-1];
        }
    }

    long long value = -10000;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            value = max(value, game[i][j]);

            long long cal_value = 0;
            for(int rec_i = 0; rec_i<=i; rec_i++)
            {
                for(int rec_j = 0; rec_j<=j; rec_j++)
                {
                    cal_value = game[i][j];
                    if(rec_j>0) cal_value -= game[i][rec_j-1];
                    if(rec_i>0) cal_value -= game[rec_i-1][j];
                    if(rec_i > 0 && rec_j > 0) cal_value += game[rec_i-1][rec_j-1];

                    value = max(value, cal_value);
                    cal_value = 0;
                }
            }
        }
    }
    cout << value;
    return 0;
}
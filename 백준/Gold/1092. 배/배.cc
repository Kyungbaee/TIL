#include <iostream>
#include <algorithm>

using namespace std;

int crane[51];
int box[10001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> crane[i];

    sort(crane, crane+n, greater<int>());

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
        cin >> box[i];

    sort(box, box+m, greater<int>());

    int time=0, c_idx=0;

    for(int i=0; i<n; i++)
    {
        if(box[c_idx] == 0)
        {
            for(int j=c_idx; j<m; j++)
            {
                if(box[c_idx] != 0)
                    break;
                else c_idx++;
            }
        }

        if(i==0) time++;

        if(box[c_idx] !=0 && box[c_idx] <= crane[i])
        {
            box[c_idx++] = 0;
            if(c_idx == m) break;
            if(i==n-1) i=-1;
            continue;
        }

        if(i!=0 && box[c_idx] > crane[i])
        {
            int chk=0;
            for(int j=c_idx; j<m; j++)
                if(box[j] != 0 && box[j] <= crane[i])
                {
                    box[j]=0;
                    chk = 1;
                    break;
                }
            if(!chk || i==n-1) i=-1;
        }

        if(i==0 && box[c_idx] > crane[i])
        {
            time = -1;
            break;
        }
    }

    cout << time;

    return 0;
}
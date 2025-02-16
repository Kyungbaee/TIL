#include <iostream>

using namespace std;

int visit[250'001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, x;
    cin >> n >> x;

    for(int i=0; i<n; i++) cin >> visit[i];

    int answer = 0;
    for(int i=0; i<x; i++) answer += visit[i];

    int* cnt = visit+1;
    int max_cnt = answer, duration = 1;

    for(int i=0; i<(n-x); i++)
    {
        max_cnt -= *(cnt-1);
        max_cnt += *(cnt+x-1);
        cnt++;

        if(answer == max_cnt) duration++;
        else if(answer < max_cnt)
        {
            answer = max_cnt;
            duration = 1;
        }
    }

    if(answer) cout << answer << "\n" << duration;
    else cout << "SAD";
    return 0;
}
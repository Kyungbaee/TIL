#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int A[10001];


int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> A[i];


    // ------------------
    // 투 포인터
    // ------------------

    int en=0, total=A[0], ans=0;
    for(int st=0; st<N; st++){
        while(en<N && total<M){
            en++;
            total += A[en];
        }
        if(en==N) break;
        if(total==M) ans++;
        total -= A[st];
    }

    cout << ans;
}
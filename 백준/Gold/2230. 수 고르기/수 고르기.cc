#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> A[i];

    sort(A, A+N);

    int st=0, en=0, ans=2000000000;

    while(st!=(N-1) || en!=(N-1)){
        if(A[en]-A[st] >= M){
            ans = min(ans, A[en]-A[st]);
            st++;
        }else if(en<N-1)
            en++;
        else break;
    }

    cout << ans;
}
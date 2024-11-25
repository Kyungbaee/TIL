#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    int N, S;
    cin >> N >> S;

    for(int i=0; i<N; i++) cin >> A[i];

    int st=0, en=0, ans=100001;

    // 합이 S 이상이면, 길이 비교 후 다음 st로 이동
    // en은 st 지점부터 시작
    int sum_case = A[0];

    for(int st=0; st<N+1; st++){
        while(en<N && sum_case<S) {
            en++;
            sum_case += A[en];
        }
        if(en==N) break;
        ans = min(ans, en-st+1);
        sum_case -= A[st];
    }

    cout << ans%100001;
}
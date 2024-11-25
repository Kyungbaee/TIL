#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int A[283201];


int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    int N, n=4000001, cnt=0;
    cin >> N;

    bool *isPrime = new bool[n+1];// n까지 구해야하므로, n+1개를 동적할당
	
	//먼저 모든 배열을 true로 초기화
	for (int i = 0; i <= n; i++) isPrime[i] = true;
 
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {//해당수가 소수라면, 출력하고 해당수를 제외한 배수들을 모두 제외
            A[cnt++] = i;
			for (int j = i * 2; j <= n; j += i) isPrime[j] = false;
		}
	}

    int en=0, total=A[0], ans=0;
    for(int st=0; A[st]<=N; st++){
        while(A[en]<N && total<N){
            en++;
            if(A[en]<=N) total += A[en];
        }
        if(A[en]>N) break;
        if(total==N) ans++;
        total -= A[st];
    }

    cout << ans;
}
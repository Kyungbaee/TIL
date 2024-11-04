#include <iostream>

using namespace std;

int n;
int answer = 0;
bool visited1[40]; // 같은 열
bool visited2[40]; // 우상단 대각선
bool visited3[40]; // 좌상단 대각선


void func(int k){
    if (k==n){
        ++answer;
        return;
    }

    for (int i=0; i<n; i++){
        if (visited1[i] || visited2[i+k] || visited3[k-i+n-1])
            continue;
        visited1[i] = 1;
        visited2[i+k] = 1;
        visited3[k-i+n-1] = 1;
        func(k+1);
        visited1[i] = 0;
        visited2[i+k] = 0;
        visited3[k-i+n-1] = 0;
    }

}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> n;
    func(0);
    cout << answer;
}
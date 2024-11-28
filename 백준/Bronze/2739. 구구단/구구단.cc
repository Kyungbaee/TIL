#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int N;
    cin >> N;

    for(int i=1; i<10; i++) cout << N << " * " << i << " = " << N*i << "\n";

    return 0;
}
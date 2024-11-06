#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    int a, b;
    cin >> a >> b;

    cout << a+b << '\n' << a-b << '\n' << a*b << '\n' << a/b << '\n' << a%b;
}
#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    string s;
    getline(cin, s);
    cout << (s[0]-'0')+(s[2]-'0');
}
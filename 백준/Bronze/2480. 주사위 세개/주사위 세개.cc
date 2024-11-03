#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int a=0, b=0, c=0;
    cin >> a >> b >> c;

    if (a==b && b==c) cout << 10000+(a)*1000;
    else if (a==b && b!=c) cout << 1000+(a)*100;
    else if (b==c && a!=c) cout << 1000+(b)*100;
    else if (a==c && b!=c) cout << 1000+(c)*100;
    else if (a!=c && a!=b && b!=c) cout << max(max(a,b),c)*100;
}
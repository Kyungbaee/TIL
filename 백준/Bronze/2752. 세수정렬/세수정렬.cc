#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int a=0, b=0, c=0;
    cin >> a >> b >> c;

    if (a>=b && b>=c) cout << c << " " << b << " " << a;
    else if(a>=b && b<c && a>=c) cout << b << " " << c << " " << a;
    else if(b>a && a>=c) cout << c << " " << a << " " << b;
    else if(b>a && a<c && b>=c) cout << a << " " << c << " " << b;
    else if(c>=a && a>=b) cout << b << " " << a << " " << c;
    else if(c>=a && a<b && c>=b) cout << a << " " << b << " " << c;
}
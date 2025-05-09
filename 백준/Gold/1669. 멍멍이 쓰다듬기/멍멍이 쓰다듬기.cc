#include <iostream>
#include <cmath>

using namespace std;


int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int x, y, cnt=0;
    cin >> x >> y;

    int diff = (y-x), root = int(sqrt(y-x));

    if(diff){
        cnt += (root-1)*2;
        int left = diff;
        for(int i=1; i<=root-1; i++) left -= i*2;
        
        for(int i=root; i>0 && left>0; i--){
            cnt += left/i;
            left = left%i;
        }
    }

    cout << cnt;
    return 0;
}
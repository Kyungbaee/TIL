#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    int answer = 0;
    int roop = n/5+1;

    while(roop--)
    {   
        int calc = roop + (n - roop*5)/2;
        
        if((n - roop*5)%2)
        {
            if(answer == 0) answer = -1;
        }
        else 
        {
            if(answer > 0) answer = min(answer, calc);
            else answer = calc;
        }
    }

    cout << answer;

    return 0;
}
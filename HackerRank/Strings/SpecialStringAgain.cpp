#include <iostream>

using namespace std;

void substrCount(int n, string s) {
    long result = n;
    
    // 연속된 같은 문자로 이루어진 문자열
    for(int i=0; i<n;){
        int repeat = 1;
        while(i+repeat < n && s[i]==s[(i+repeat)]) repeat++;
        
        result += repeat*(repeat-1)/2;
        i += repeat;
    }
    
    // 팰린드롬
    for(int i=1; i<n-1; i++){
        int offset = 1;
        while(
            (i+offset < n) &&
            (i-offset >= 0) &&
            (s[i-offset] == s[i-1]) &&
            (s[i+offset] == s[i+1]) &&
            (s[i-1] != s[i]) &&
            (s[i-1] == s[i+1])
        ){
            offset++;
            result++;
        }
    }

    cout << result << "\n";
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    string s;
    cin >> s;

    substrCount(n, s);

    return 0;
}

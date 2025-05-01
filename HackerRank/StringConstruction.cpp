#include <iostream>

using namespace std;

int stringConstruction(string s) {
    int freq[26] = {}, cnt = 0;
    
    for(char c : s) {
        if(freq[(c-'a')]==0) {
            cnt++;
            freq[(c-'a')]=1;
        }
    }

    return cnt;
}


int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        cout << stringConstruction(s) << "\n";
    }

    return 0;
}
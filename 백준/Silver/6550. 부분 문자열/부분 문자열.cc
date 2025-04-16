#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    while(true)
    {
        string s, t;
        cin >> s >> t;

        if(s.empty() && t.empty()) break;

        int idx=0;

        for(int i=0; i<t.length(); i++)
        {
            if(t[i]==s[idx]) idx++;
        }

        if(idx == s.length()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int answer;
string s, t;

void solve(string t)
{
    if(s.length() == t.length())
    {
        if(s==t) answer = 1;
        return;
    }

    if(answer) return;
    
    string nxt;
    if(t.back() == 'A') 
    {
        solve(t.substr(0,t.length()-1));
    }
    if(t.front() == 'B')
    {
        reverse(t.begin(), t.end());
        solve(t.substr(0,t.length()-1));
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    cin >> s >> t;
    solve(t);
    cout << answer;
    return 0;
}
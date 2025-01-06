#include <iostream>
#include <vector>

using namespace std;

// 실패 함수 세팅
vector<int> fail(string& s)
{
    vector<int> f(s.size());
    int j = 0;
    for(int i=1; i<(int)s.size(); i++)
    {
        while(j>0 && s[i]!=s[j]) j = f[j-1];
        if(s[i]==s[j]) f[i] = ++j;
    }
    return f;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    string s, K;
    cin >> s >> K;
    vector<int> f = fail(K);
    int j = 0;

    string S;
    for (char c : s) 
        if (!(c >= '0' && c <= '9')) S += c;    // 문자만 추출

    for(int i = 0; i < (int)S.size(); i++){
        while(j > 0 && S[i] != K[j]) j = f[j-1]; // j=0가 될 때까지 문자열 밀어주기
        if(S[i] == K[j]) j++;   // 한글자 일치 -> 다음 문자로 이동
        if(j == (int)K.size())   // 일치하는 문자열 발견
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
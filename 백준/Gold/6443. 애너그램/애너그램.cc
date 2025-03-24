#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
bool visited[21];

void anagram(string word){
    if(word.length() == s.length())
    {
        cout << word << "\n";
        return;
    }

    char last_char = ' ';

    for(int i=0; i<s.length(); i++)
    {
        if(!visited[i] && s[i] != last_char)
        {
            visited[i]=true;
            last_char = s[i];
            anagram(word+s[i]);
            visited[i]=false;
        }
    }

}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    while(n--)
    {
        cin >> s;
        sort(s.begin(), s.end());
        fill(visited, visited+21, false);
        anagram("");
    }
    return 0;
}
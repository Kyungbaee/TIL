#include <iostream>

using namespace std;

int makingAnagrams(string s1, string s2) {
    int result = 0;
    int freq[26] = {};
    
    for(char c : s1) freq[(c-'a')]++;
    for(char c : s2) freq[(c-'a')]--;
    for(int i=0; i<26; i++) if(freq[i] != 0 ) result += abs(freq[i]);
    
    return result;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    string s1, s2;
    cin >> s1 >> s2;

    int result = makingAnagrams(s1, s2);
    cout << result << "\n";
    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;

void Anagram(string s){
    unordered_map<string, int> m;
    int result = 0;

    for(int i=0; i<s.length(); i++){
        int freq[26] = {};
        
        for(int j=i; j<s.length(); j++){
            freq[s[j]-'a']++;

            string key = "";
            for(int k=0; k<26; k++) key += to_string(freq[k]);
            m[key]++;
        }
    }

    for(auto [key, count] : m){
        if(count > 1){
            result += (count * (count-1)) / 2;
        }
    }

    cout << result << "\n";
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int q;
    cin >> q;

    while(q--){
        string s;
        cin >> s;

        Anagram(s);
    }

    return 0;
}

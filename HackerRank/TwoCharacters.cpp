#include <iostream>
#include <vector>

using namespace std;

// 개선 버전
int alternate(string s) {
    int result = 0;
    int chk[26] = {};
    vector<char> freq;

    // 중복 없는 문자 모음 생성
    for (char ch : s) {
        if (!chk[ch - 'a']) {
            chk[ch - 'a'] = 1;
            freq.push_back(ch);
        }
    }

    for (int i = 0; i < freq.size(); ++i) {
        for (int j = i + 1; j < freq.size(); ++j) {
            char a = freq[i], b = freq[j];
            string filtered = "";

            for (char ch : s) {
                if (ch == a || ch == b) {
                    filtered += ch;
                }
            }

            if (filtered.length() < 2) continue;

            bool isValid = true;
            for (int k = 1; k < filtered.size(); ++k) {
                if (filtered[k] == filtered[k - 1]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result = max(result, (int)filtered.size());
            }
        }
    }

    return result;
}


void TwoCharaters(string s){
    int result = 0;
    
    vector<char> freq;
    int chk[26] = {};
    
    for(int i=0; i<s.length(); i++) {
        if(chk[(s[i]-'a')] == 0){
            freq.push_back(s[i]);
            chk[(s[i]-'a')]=1;
        }
    }
        
    int len = freq.size();
    vector<bool> temp(len);
    fill(temp.end()-(len-2), temp.end(), true);
    
    do{
        string new_S = s;
        for(int i=0; i<s.length(); i++){
            if(temp[i]){
                char c = freq[i];
                
                while(new_S.find(c) != std::string::npos){
                    new_S.erase(find(new_S.begin(), new_S.end(), c));
                }
            }
        }
        
        if(new_S.length() < 2) continue;
        
        char prevChar = ' ';
        for(int i=0; i<new_S.length(); i++){
            if(prevChar != new_S[i]){
                prevChar = new_S[i];
                if(i == new_S.length()-1) 
                    result = (result < new_S.length()) ? new_S.length() : result;
            }
            else if(prevChar == new_S[i]) break;
        }
        
    }while(next_permutation(temp.begin(), temp.end()));
    
    cout <<  result << "\n";
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    string s;
    cin >> s;

    TwoCharaters(s);
    return 0;
}
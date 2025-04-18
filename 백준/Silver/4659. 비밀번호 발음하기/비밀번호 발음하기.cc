#include <iostream>

using namespace std;

void print_false(string s){
    cout << "<" << s << "> " << "is not acceptable.\n";
}

void print_true(string s){
    cout << "<" << s << "> " << "is acceptable.\n";
}

bool continuous_word(string s){
    int cnt = 0;
    for(char c : s){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            if(cnt<0) cnt = 0;
            cnt++;
        }
        else {
            if(cnt>0) cnt = 0;
            cnt--;
        }

        if(cnt==3 || cnt==-3) return true;
    }
    return false;
}

bool double_word(string s){
    char prev_word = ' ';
    for(char c : s){
        if(prev_word == c && (prev_word != 'e' && prev_word != 'o'))
            return true;
        prev_word = c;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    while(true)
    {
        string s;
        cin >> s;

        if(s == "end") break;
        
        if(string::npos==s.find("a") && string::npos==s.find("e") && string::npos==s.find("i") \
            && string::npos==s.find("o") && string::npos==s.find("u"))
            print_false(s);
        else if(continuous_word(s)) print_false(s);
        else if(double_word(s)) print_false(s);
        else print_true(s);
    }

    return 0;
}
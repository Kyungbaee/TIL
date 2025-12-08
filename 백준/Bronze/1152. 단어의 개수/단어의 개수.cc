#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    // 공백 포함 한 줄 전체 입력
    if (!getline(cin, s)) {
        cout << 0;
        return 0;
    }

    int count = 0;
    bool inWord = false;

    for (char c : s) {
        if (c == ' ') {
            // 공백이면 단어 구간 종료
            inWord = false;
        } else {
            // 공백이 아닌 문자를 처음 만날 때 단어 하나 추가
            if (!inWord) {
                inWord = true;
                count++;
            }
        }
    }

    cout << count;
    return 0;
}

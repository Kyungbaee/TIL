#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
    vector<string> chk;

    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;

        auto it = find(chk.begin(), chk.end(), s);
        if(it == chk.end()){
            q.push(make_pair(s.length(), s));
            chk.push_back(s);
        }
    }

    for(int i=0; i<chk.size(); i++)
    {
        auto value = q.top();
        int size = value.first;
        string s = value.second;

        cout << s << "\n";
        q.pop();
    }
    return 0;
}
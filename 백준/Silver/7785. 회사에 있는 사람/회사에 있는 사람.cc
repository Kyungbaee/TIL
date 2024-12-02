#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    unordered_set<string> s;
    //unordered_multiset<int> ms;
    //unordered_map<string, int> m;

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        string name, log;
        cin >> name >> log;
        if(log == "enter")
            s.insert(name);
        else
            s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto x: ans) cout << x << "\n";

    return 0;
}
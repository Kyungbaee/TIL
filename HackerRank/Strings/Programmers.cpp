#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    string s;
    cin >> s;

    vector<pair<int, int>> combi;
    int prev_idx = 0;

    while(true){
        if(s.find("programmer", prev_idx) == std::string::npos) break;
        prev_idx = s.find("programmer", prev_idx);
        combi.push_back(make_pair(prev_idx, prev_idx+9));
        prev_idx += 9;
    }

    unordered_map<int, int> um;

    for(int i=1; i<combi.size(); i++){
        int finish_idx = combi[i-1].second;
        int start_idx = combi[i].first;
        int distance = start_idx-(finish_idx+1);

        um[distance]++;
    }

    int answer = 0;
    for(auto cnt : um){
        if(cnt.second){
            answer = cnt.second;
            break;
        }
    }

    cout << answer;
    return 0;
}

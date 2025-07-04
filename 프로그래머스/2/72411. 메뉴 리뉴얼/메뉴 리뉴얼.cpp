#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
map<int, int> cnt;

void combi(string s){
    int len = s.size();

	for (int i = 2; i <= len; i++) {
		vector<bool> v(len - i, false);
		v.insert(v.end(), i, true);

		do {
			string temp = "";
			for (int k = 0; k < len; k++) {
				if (v[k]) temp += s[k];
			}
			m[temp]++;
		} while (next_permutation(v.begin(), v.end()));

	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string order : orders){
        sort(order.begin(), order.end());
        combi(order);
    }
    
    for(int i : course) cnt[i] = 2;
    
    for (map<string, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
        cnt[(itr->first).length()] = max(cnt[(itr->first).length()], itr->second);

    for(int i : course){
        for (map<string, int>::iterator itr = m.begin(); itr != m.end(); ++itr){
            if((itr->first).length()==i && cnt[i]==(itr->second)) answer.push_back(itr->first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
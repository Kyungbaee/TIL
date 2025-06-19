#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> banCheck;
map<string, int> banCount;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(string s : report){
        vector<string> sp = split(s, " ");
        auto it = find(banCheck[sp[0]].begin(), banCheck[sp[0]].end(), sp[1]);
        if(it == banCheck[sp[0]].end()){
            banCheck[sp[0]].push_back(sp[1]);
            banCount[sp[1]]++;
        }
    }
    
    for(string id : id_list){
        int reportCount = 0;
        for(string ban_id : banCheck[id])
            if(banCount[ban_id] >= k) reportCount++;
        answer.push_back(reportCount);
    }
    
    return answer;
}
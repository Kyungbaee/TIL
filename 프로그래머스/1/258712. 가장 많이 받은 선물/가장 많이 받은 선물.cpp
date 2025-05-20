#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, map<string, int>> m;
map<string, int> jisu;
map<string, int> present;

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

int solution(vector<string> friends, vector<string> gifts) {
    
    // 선물 기록
    for(string s : gifts){
        vector<string> sp = split(s, " ");
        m[sp[0]][sp[1]]++;
        m[sp[1]][sp[0]]--;
    }
    
    // 선물 지수 계산
    for(string s : friends){
        for(string ss : friends){
            if(m[s].find(ss) != m[s].end()) jisu[s] += m[s][ss];
        }
    }

    // 선물 교환
    for(string s : friends){
        for(string ss : friends){
            if(m[s][ss] > 0) present[s]++;
            else if((m[s][ss] == 0) && (jisu[s] > jisu[ss])) present[s]++;
        }
    }
    
    // 최대 선물 갯수
    int answer = 0;
    for(string s : friends){
        if(present[s] > answer) answer = present[s];
    }
    
    return answer;
}
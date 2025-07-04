#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, vector<int>> infos;

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


int keyToCount(vector<string> keys, int score){
    int count = 0;
    for(string key : keys){
        if(infos[key].empty()) continue;
        int st = 0, end = infos[key].size();
        {
            while(st < end){
                int mid = (st+end)/2;
                if(infos[key][mid] < score)
                    st = mid+1;
                else
                    end = mid;
            }
        }
        count += (infos[key].size()-st);
    }
    
    return count;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for(string s : info){
        vector<string> v;
        v = split(s, " ");
        
        string key = "";
        if(v[0]=="cpp") key += "0";
        else if(v[0]=="java") key += "1";
        else key += "2";
        
        if(v[1]=="backend") key += "0";
        else key += "1";
        
        if(v[2]=="junior") key += "0";
        else key += "1";
        
        if(v[3]=="chicken") key += "0";
        else key += "1";
        
        infos[key].push_back(stoi(v[4]));
    }
    
    for (auto& [key, vec] : infos)
        sort(vec.begin(), vec.end());
    
    for(string s : query){
        vector<string> v;
        while (s.find(" and ") != string::npos)
            s.replace(s.find(" and "), 5, " ");

        v = split(s, " ");
        
        vector<string> keys;
        if(v[0]=="cpp") keys.push_back("0");
        else if(v[0]=="java") keys.push_back("1");
        else if(v[0]=="python") keys.push_back("2");
        else{
            keys.push_back("0");
            keys.push_back("1");
            keys.push_back("2");
        }
        
        vector<string> secondKeys;
        for(string key : keys){
            if(v[1]=="backend") secondKeys.push_back(key+"0");
            else if(v[1]=="frontend") secondKeys.push_back(key+"1");
            else{
                secondKeys.push_back(key+"0");
                secondKeys.push_back(key+"1");
            }
        }

        vector<string> thirdKeys;
        for(string key : secondKeys){
            if(v[2]=="junior") thirdKeys.push_back(key+"0");
            else if(v[2]=="senior") thirdKeys.push_back(key+"1");
            else{
                thirdKeys.push_back(key+"0");
                thirdKeys.push_back(key+"1");
            }
        }

        vector<string> finalKeys;
        for(string key : thirdKeys){
            if(v[3]=="chicken") finalKeys.push_back(key+"0");
            else if(v[3]=="pizza") finalKeys.push_back(key+"1");
            else{
                finalKeys.push_back(key+"0");
                finalKeys.push_back(key+"1");
            }
        }
        
        answer.push_back(keyToCount(finalKeys, stoi(v[4])));
    }
    
    return answer;
}
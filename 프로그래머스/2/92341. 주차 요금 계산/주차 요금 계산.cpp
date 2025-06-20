#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> m;

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

int totaltime(string start, string end){
    vector<string> stTime = split(start, ":");
    int stHour = stoi(stTime[0]), stMin = stoi(stTime[1]);
    
    vector<string> endTime = split(end, ":");
    int endHour = stoi(endTime[0]), endMin = stoi(endTime[1]);
    
    int min = endMin - stMin;
    if(min < 0) {
        endHour--;
        min += 60;
    }
    int hour = endHour - stHour;
    int totalMin = min + (hour)*60;
    
    return totalMin;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    vector<string> carNumbers;
    for(string r : records){
        vector<string> record = split(r, " ");
        string carNumber = record[1];
        
        if(find(carNumbers.begin(), carNumbers.end(), carNumber) == carNumbers.end())
            carNumbers.push_back(carNumber);
        
        m[carNumber].push_back(record[0]);
    }
    
    sort(carNumbers.begin(), carNumbers.end());
    for(string cn : carNumbers) {
        int time = 0;
        for(int i=0; i<m[cn].size(); i=i+2){
            if(m[cn].size() > (i+1)) time += totaltime(m[cn][i], m[cn][i+1]);
            else time += totaltime(m[cn][i], "23:59");
        }
        
        if(fees[0] >= time) answer.push_back(fees[1]);
        else {
            if((time-fees[0])%fees[2] == 0)
                answer.push_back((fees[1] + ((time-fees[0])/fees[2]) * fees[3]));
            else
                answer.push_back((fees[1] + ((time-fees[0])/fees[2]+1) * fees[3]));
        }
    }
    return answer;
}
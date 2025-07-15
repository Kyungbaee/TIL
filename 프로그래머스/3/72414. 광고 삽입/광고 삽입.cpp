#include <string>
#include <vector>
#include <iostream>

using namespace std;

int stamp[360001];

int stringToTime(string s){
    int time = stoi(s.substr(0,2)) * 3600 + stoi(s.substr(3,2)) * 60 + stoi(s.substr(6,2));    
    return time;
}

string timeToString(int n){
    string s;
    if((n/3600) < 10) s += "0";
    s += to_string(n/3600) + ":";
    n %= 3600;
    if((n/60) < 10) s += "0";
    s += to_string(n/60)+ ":";
    n %= 60;
    if(n < 10) s += "0";
    s += to_string(n);
    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "00:00:00";
    
    for(string s : logs){
        string startTime = s.substr(0,8), endTime = s.substr(9,8);
        stamp[stringToTime(startTime)]++;
        stamp[stringToTime(endTime)]--;
    }
    
    for(int i=1; i<=360000; i++) stamp[i] += stamp[i-1];
    
    long long watchingCount = 0, compareCount;
    for(int i=0; i<stringToTime(adv_time); i++) compareCount += stamp[i];
    
    watchingCount = compareCount;
    for(int i=1; i<= 360000-stringToTime(adv_time); i++){
        compareCount = compareCount-stamp[i-1]+stamp[i+stringToTime(adv_time)-1];
        if(compareCount > watchingCount) {
            watchingCount = compareCount;
            answer = timeToString(i);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> term;

vector<string> split(string input, string delimiter) {    
    vector<string> ret;    
    long long pos = 0;    
    string token = "";    
    
    while((pos = input.find(delimiter)) != string::npos) 
    {        
        token = input.substr(0, pos);        
        ret.push_back(token);        
        input.erase(0, pos + delimiter.length());    
    }    
    
    ret.push_back(input);    
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<string> t_result = split(today, ".");
    int t_year = stoi(t_result[0]), t_month = stoi(t_result[1]), t_day = stoi(t_result[2]);

    for(string s : terms) {
        vector<string> result = split(s, " ");
        term[result[0]] = stoi(result[1]);
    }
    
    for(int i=0; i<privacies.size(); i++){
        string s = privacies[i];
        vector<string> result = split(s, " ");
        string contract = result[0], type = result[1];
        
        result = split(contract, ".");
        int year = stoi(result[0]), month = stoi(result[1]), day = stoi(result[2]);
        
        int deadline = term[type];
        if(day == 1) deadline -= 1;
        day = (day == 1) ? 28 : day-1;
        
        month += deadline;
        if(month > 12) {
            year += (month-1)/12;
            month -= (month-1)/12*12;
        }
        
        int idx = i+1;
        if(t_year > year) answer.push_back(idx);
        else if(t_year < year) continue;
        else {
            if(t_month > month) answer.push_back(idx);
            else if(t_month < month) continue;
            else{
                if(t_day > day) answer.push_back(idx);
                else continue;
            }
        }
    }
    return answer;
}
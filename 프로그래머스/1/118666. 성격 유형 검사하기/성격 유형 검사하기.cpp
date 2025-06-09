#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> m;
    string s[4] = {"RT", "CF", "JM", "AN"};
    
    for(int i=0; i<survey.size(); i++){
        if(choices[i] < 4) m[survey[i][0]] += abs(choices[i]-4);
        else if(choices[i] > 4) m[survey[i][1]] += choices[i]-4;
    }
    
    for(string ss : s){
        if(m[ss[0]] < m[ss[1]]) answer += ss[1];
        else answer += ss[0];
    }
    
    return answer;
}
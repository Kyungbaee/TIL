class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int answer = 0;
        for(string s : patterns) if(word.find(s) != string::npos) answer++;
        return answer;
    }
};
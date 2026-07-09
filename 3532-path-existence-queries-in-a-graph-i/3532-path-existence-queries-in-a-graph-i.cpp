class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> lineNumber(n+1, 0);
        for(int i=0; i<n; i++) lineNumber[i] = i*-1;
        int line = 1;

        for(int i=0; i<n-1; i++){
            if((abs(nums[i] - nums[i+1]) <= maxDiff)){
                lineNumber[i] = line, lineNumber[i+1] = line;
            }
            else line++;
        }

        vector<bool> answer;
        for(vector<int> query : queries){
            if(lineNumber[query[0]] == lineNumber[query[1]]) answer.push_back(true);
            else answer.push_back(false);
        }

        return answer;
    }
};
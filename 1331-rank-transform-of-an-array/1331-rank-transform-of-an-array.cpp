class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;
        vector<int> endArray, answer;

        for(int num : arr) s.insert(num);
        for(int num : s) endArray.push_back(num);

        for(int num : arr){
            auto it = lower_bound(endArray.begin(), endArray.end(), num);
            int idx = it - endArray.begin();
            answer.push_back(idx+1);
        }

        return answer;
    }
};
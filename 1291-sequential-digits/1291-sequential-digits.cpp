class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        set<int> s;
        vector<int> answer;

        for(int i=0; i<int(digits.size()); i++){
            string str = "";
            str += digits[i];
            for(int j=i+1; j<=8; j++){
                str += digits[j];
                s.insert(stoi(str));
            }
        }

        for(int num : s) {
            if(num >= low && num <= high) answer.push_back(num);
            if(num > high) break;
        }

        return answer;
    }
};
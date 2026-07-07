class Solution {
public:
    long long sumAndMultiply(int n) {
        string digit = to_string(n), nonZero = "";
        int sum = 0;

        for(char c : digit) {
            if(c != '0') {
                nonZero += c;
                sum += c-'0';
            }
        }

        if(nonZero == "") return 0;
        
        long long answer = stoll(nonZero) * (long long)sum;
        return answer;
    }
};
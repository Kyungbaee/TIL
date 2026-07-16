class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long answer = 0;
        int mx = 0;
        vector<int> prefixGcd;

        for(int num : nums){
            mx = max(mx, num);
            prefixGcd.push_back(gcd(num, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        
        for(int i=0; i<int((int)prefixGcd.size()/2); i++){
            answer += gcd(prefixGcd[i], prefixGcd[(int)prefixGcd.size()-i-1]);
        }

        return answer;
    }
};
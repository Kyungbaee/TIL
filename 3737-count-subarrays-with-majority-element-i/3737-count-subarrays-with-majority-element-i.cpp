class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for(int num : nums) cout << num;
        int answer = 0;
        for(int i=1; i<=int(nums.size()); i++){
            int temp = 0;

            // init
            for(int j=0; j<i; j++) if(nums[j] == target) temp++;
            if (temp > (i/2)) answer++;

            // sliding window
            for(int j=0; j+i<int(nums.size()); j++){
                if(nums[j] == target) temp--;
                if(nums[j+i] == target) temp++;
                if (temp > (i/2)) answer++;
            }
        }

        return answer;
    }
};
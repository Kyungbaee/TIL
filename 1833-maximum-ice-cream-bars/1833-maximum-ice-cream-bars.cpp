class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> v = costs;
        sort(v.begin(), v.end());

        int count = 0;
        for(int num : v){
            if(num <= coins){
                coins -= num;
                count++;
            }
            else break;
        }
        return count;
    }
};
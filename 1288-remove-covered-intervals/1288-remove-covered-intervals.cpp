class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int st = intervals[0][0], ed = intervals[0][1], answer = 1;

        for(vector<int> itv : intervals){
            int itvSt = itv[0], itvEd = itv[1];

            if(st <= itvSt && itvEd <= ed) continue;
            answer++;
            ed = itvEd;
        }

        return answer;
    }
};
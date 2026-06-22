class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string balloon = "balloon";
        map<char, int> m;

        int minNum = 10'000;

        for(char c : text) m[c]++;
        for(char c : balloon){
            if(c == 'l' || c == 'o') minNum = min(minNum, m[c]/2);
            else minNum = min(minNum, m[c]);
        }

        return minNum;
    }
};
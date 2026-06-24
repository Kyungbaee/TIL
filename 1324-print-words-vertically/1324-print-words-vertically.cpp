class Solution {
public:
    vector<string> printVertically(string s) {
        string temp = "";
        vector<string> splitString, answer;
        int maxLength = 0;

        for(char c : s){
            if(c != ' ') temp += c;
            else{
                splitString.push_back(temp);
                maxLength = max(maxLength, int(temp.size()));
                temp = "";
            } 
        }
        if(temp != "") {
            maxLength = max(maxLength, int(temp.size()));
            splitString.push_back(temp);
        }


        for(int i=0; i<maxLength; i++){
            string stTemp = "";
            for(string sp : splitString){
                if(int(sp.size()) > i) stTemp += sp[i];
                else stTemp += " ";
            }

            bool tag = false;
            string trimString = "";
            for(int j=int(stTemp.size())-1; j>=0; j--){
                if(stTemp[j] != ' '){
                    tag = true;
                    trimString += stTemp[j];
                }
                else if(tag) trimString += ' ';
            }
            reverse(trimString.begin(), trimString.end());
            answer.push_back(trimString);
        }

        return answer;
    }
};
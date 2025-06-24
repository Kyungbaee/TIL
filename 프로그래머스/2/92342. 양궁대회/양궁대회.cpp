#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answers;
vector<int> arrows, result;
int arrow = 0, diff = 0, arrowsLeft = 0;

void chkScore(int idx){
    if(idx == 11) {
        int aScore = 0, lScore = 0, costArrow = 0;
        
        for(int i=0; i<=10; i++){
            if(result[i]==2) { 
                lScore += (10-i);
                costArrow += (arrows[i]+1);
            }
            else if(result[i]==1 && arrows[i] > 0) {
                aScore += (10-i); 
                costArrow += (arrows[i]);
            }
            else if(result[i]==0) aScore += (10-i);
        }
        
        if((costArrow > arrow) || (lScore-aScore < diff)) return;
        if((lScore-aScore) > diff) answers.clear();
        diff = (lScore - aScore);
        arrowsLeft = arrow - costArrow;

        vector<int> answer;
        for(int i=10; i>=0; i--) {
            if(result[i]==2) answer.push_back(arrows[i]+1);
            else if(result[i]==1) answer.push_back(arrows[i]);
            else answer.push_back(0);
        }

        answers.push_back(answer);
        return ;
    }
    else{
        for(int i=2; i>=0; i--){
            result.push_back(i);
            chkScore(idx+1);
            result.pop_back();
        }
    }
}

vector<int> solution(int n, vector<int> info) { 
    for(int i : info) arrows.push_back(i);
    arrow = n;
    chkScore(0);
    
    sort(answers.begin(), answers.end());
    reverse(answers.begin(), answers.end());
    
    if(answers.empty() || diff == 0) return {-1};
    
    vector<int> answer;
    for(int i=10; i>=0; i--) answer.push_back(answers[0][i]);
    if(arrowsLeft > 0) answer[10] += arrowsLeft;
    return answer;
}
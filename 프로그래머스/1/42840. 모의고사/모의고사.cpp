#include <string>
#include <vector>

using namespace std;

int person1[5] = {1, 2, 3, 4, 5}, cnt1 = 0;
int person2[8] = {2, 1, 2, 3, 2, 4, 2, 5}, cnt2 = 0;
int person3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}, cnt3 = 0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i=0; i<answers.size(); i++){
        if(person1[i%5] == answers[i]) cnt1++;
        if(person2[i%8] == answers[i]) cnt2++;
        if(person3[i%10] == answers[i]) cnt3++;
    }
    
    if((cnt1 == cnt2) && (cnt2 == cnt3)) return {1,2,3};
    if((cnt1 == cnt2) && (cnt2 > cnt3)) return {1,2};
    if((cnt1 == cnt3) && (cnt3 > cnt2)) return {1,3};
    if((cnt2 == cnt3) && (cnt2 > cnt1)) return {2,3};
    if((cnt1 > cnt2) && (cnt1 > cnt3)) return {1};
    if((cnt2 > cnt1) && (cnt2 > cnt3)) return {2};
    if((cnt3 > cnt2) && (cnt3 > cnt1)) return {3};
}
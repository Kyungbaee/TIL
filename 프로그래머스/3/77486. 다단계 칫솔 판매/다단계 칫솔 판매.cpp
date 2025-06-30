#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parent;
map<string, vector<int>> revenue;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    parent["-"] = "center";
    for(int i=0; i<enroll.size(); i++) parent[enroll[i]] = referral[i];
    for(int i=0; i<seller.size(); i++){
        string name = seller[i];
        int money = amount[i]*100;
        revenue[name].push_back(money);
        
        while(parent[name] != "center" && revenue[name].back()>=10){
            money = revenue[name].back();
            revenue[name].pop_back();
            
            revenue[name].push_back(money - (money/10));
            revenue[parent[name]].push_back(money/10);
            name = parent[name];
        }
    }
    
    for(string name : enroll){
        int sum = 0;
        for(int num : revenue[name]) sum += num;
        answer.push_back(sum);
    }
    return answer;
}
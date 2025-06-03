#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 이모티콘 4의 7승 = 16384
int discount[4] = {10, 20, 30, 40};
long long r_plus = 0, r_sales = 0;


void recursive(vector<vector<int>> users, vector<int> emoticons, vector<pair<int, int>> v, int depth){
    if(v.size() == emoticons.size()){
        long long result[101];
        long long plus = 0, sales = 0;
        fill(result, result+users.size(), 0);
        
        for(int i=0; i<users.size(); i++){
            for(pair<int, int> p : v){
                if(p.second >= users[i][0]){
                    result[i] += (p.first - (p.first/100*p.second));
                }
            }
            if(result[i] >= users[i][1]) {
                result[i] = 0;
                plus++;
            }
        }

        for(int i=0; i<users.size(); i++){
            sales += result[i];
        }

        if(plus > r_plus){
            r_plus = plus;
            r_sales = sales;
        }
        else if(plus == r_plus){
            if(sales > r_sales) r_sales = sales;
        }
        
        return;
    }
    
    for(int i=0; i<4; i++){
        v.push_back({emoticons[depth], discount[i]});
        recursive(users, emoticons, v, depth+1);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<pair<int, int>> v;
    recursive(users, emoticons, v, 0);
        
    answer.push_back(r_plus);
    answer.push_back(r_sales);
    return answer;
}
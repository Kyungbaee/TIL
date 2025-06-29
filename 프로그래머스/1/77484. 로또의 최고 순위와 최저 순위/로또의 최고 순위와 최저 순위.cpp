#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int winCount = 0, zeroCount = 0;
    
    for(int num : lottos){
        if(find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            winCount++;
        if(num == 0)
            zeroCount++;
    }
    
    int result[7] = {6, 6, 5, 4, 3, 2, 1};
    answer.push_back(result[(winCount+zeroCount)]);
    answer.push_back(result[winCount]);
    return answer;
}
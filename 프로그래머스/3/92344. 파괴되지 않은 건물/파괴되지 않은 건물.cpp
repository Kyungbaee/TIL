#include <string>
#include <vector>

using namespace std;

long building[1002][1002];
long prefixSum[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int answer = 0;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++)
            building[i][j] = board[i][j];
    }
    
    for(vector<int> skill : skills){
        int type = skill[0], r1 = skill[1], c1 = skill[2], r2 = skill[3], c2 = skill[4], degree = skill[5];
        
        if(type == 1) type = -1;
        else type = 1;
        
        prefixSum[r1][c1] += (degree*type);
        prefixSum[r2+1][c2+1] += (degree*type);
        prefixSum[r2+1][c1] -= (degree*type);
        prefixSum[r1][c2+1] -= (degree*type);
    }
    
    for(int i=0; i<board.size(); i++){
        for(int j=1; j<board[0].size(); j++)
            prefixSum[i][j] += prefixSum[i][j-1];
    }
    
    for(int i=1; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++)
            prefixSum[i][j] += prefixSum[i-1][j];
    }
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            building[i][j] += prefixSum[i][j];
            if(building[i][j]>=1) answer++;
        }
    }
    
    return answer;
}
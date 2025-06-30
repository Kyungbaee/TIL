#include <string>
#include <vector>
#include <deque>

using namespace std;

int board[102][102];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int num = 1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++)
            board[i][j] = num++;
    }
    
    for(vector<int> v : queries){
        int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3], minNum = 10001;
        deque<int> left, right, top, bottom;
        
        for(int i=x1; i<=x2; i++) 
        {
            if(i == x1) for(int j=y1+1; j<y2; j++) {
                if(board[i][j] < minNum) minNum = board[i][j];
                top.push_back(board[i][j]);
            }
            if(i == x2) for(int j=y1+1; j<y2; j++) {
                if(board[i][j] < minNum) minNum = board[i][j];
                bottom.push_back(board[i][j]);
            }
            if(board[i][y1] < minNum) minNum = board[i][y1];
            if(board[i][y2] < minNum) minNum = board[i][y2];
            left.push_back(board[i][y1]);
            right.push_back(board[i][y2]);
        }
        
        answer.push_back(minNum);
        
        top.push_front(left.front());
        left.pop_front();
        right.push_front(top.back());
        top.pop_back();
        bottom.push_back(right.back());
        right.pop_back();
        left.push_back(bottom.front());
        bottom.pop_front();
        
        for(int i=x1; i<=x2; i++) 
        {
            if(i == x1) for(int j=y1+1; j<y2; j++) {
                board[i][j] = top.front();
                top.pop_front();
            }
            if(i == x2) for(int j=y1+1; j<y2; j++) {
                board[i][j] = bottom.front();
                bottom.pop_front();
            }
            board[i][y1] = left.front();
            left.pop_front();
            board[i][y2] = right.front();
            right.pop_front();
        }
    }
    return answer;
}
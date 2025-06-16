#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int r = rc.size(), c = rc[0].size();
    deque<int> left, right, dq;
    deque<deque<int>> center;
    
    for(int i=0; i<r; i++) {
        dq.clear();
        for(int j=0; j<c; j++)
        {
            if(j==0) left.push_back(rc[i][j]);
            else if(j==(c-1)) right.push_back(rc[i][j]);
            else dq.push_back(rc[i][j]);
        }
        center.push_back(dq);
    }
    
    for(string s : operations){
        if(s == "ShiftRow"){
            left.push_front(left.back());
            right.push_front(right.back());
            center.push_front(move(center.back()));  // deep copy -> shallow copy
            left.pop_back();
            right.pop_back();
            center.pop_back();
        }
        else{
            // 좌측 상단
            center[0].push_front(left.front());
            left.pop_front();
            // 우측 상단
            right.push_front(center[0].back());
            center[0].pop_back();
            // 우측 하단
            center[(r-1)].push_back(right.back());
            right.pop_back();
            // 좌측 하단
            left.push_back(center[(r-1)].front());
            center[(r-1)].pop_front();
        }
    }
    
    for(int i=0; i<r; i++){
        vector<int> v;
        v.push_back(left[i]);
        for(int num : center[i]) v.push_back(num);
        v.push_back(right[i]);
        answer.push_back(v);
    }
    return answer;
}
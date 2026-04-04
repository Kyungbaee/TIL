#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// col번째 컬럼의 값 기준 오름차순
// 동일하면 첫 번째 컬럼의 값을 기준으로 내림차순 정렬

// S_i = i번째 행의 튜플에 대해 각 컬럼의 값을 i로 나눈 나머지들의 합으로 정의
// row_begin ≤ i ≤ row_end 인 모든 S_i를 누적하여 bitwise XOR 한 값을 해시 값으로서 반환

vector<int> S;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {  
    sort(data.begin(), data.end(), [col](const vector<int>&left, const vector<int>& right){
        if(left[col-1] != right[col-1]){
            return left[col-1] < right[col-1];
        }
        return left[0] > right[0];
    });
    
    for(int i=row_begin; i<=row_end; i++){
        int temp = 0;
        for(int d : data[i-1]) temp += (d % i);
        S.push_back(temp);
    }
    
    if(S.size() == 1) return S.back();
    
    for(int i=1; i<S.size(); i++){
        S[i] = (S[i-1] ^ S[i]);
    }

    return S.back();
}
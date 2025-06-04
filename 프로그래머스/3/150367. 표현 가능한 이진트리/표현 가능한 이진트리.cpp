#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <iostream>

using namespace std;

// 포화 이진 트리 : 서브 트리까지 모두 꽉 찬 트리
// 리프 노드 : 자식 노드가 없는 노드
// 3번 조건과 추가 가정사항은 중위 탐색을 말한다.

// 숫자 -> 이진수 -> 루트에 0이 있으면 불가능.
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long number : numbers){
        bitset<64> b(number);
        string s = b.to_string();
        
        int idx = -1;
        for(char c : s) {
            idx++;
            if(c == '1') break;
        }
        
        int depth = 0;
        for(int i=1; i<=6; i++){
            if((64-idx) < pow(2, i)){
                depth = i;
                break;
            }
        }
        
        int sum_element[7] = {0, 1, 3, 7, 15, 31, 63};
        string sub_s = s.substr(64-sum_element[depth]);

        bool chk = false;
        for(int i=2; i<=depth && !chk; i++){
            for(int j=pow(2,i-1); j<=sub_s.length() && !chk; j+=pow(2,i)){
                if(sub_s[(j-1)] == '0'){
                    int child = pow(2, i-2);
                    if(sub_s[(j-child-1)] == '1') chk = true;
                    if(sub_s[(j+child-1)] == '1') chk = true;
                }
            }
        }
        
        if(chk) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}
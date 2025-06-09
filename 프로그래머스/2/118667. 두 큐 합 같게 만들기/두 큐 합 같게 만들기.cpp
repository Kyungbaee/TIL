#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    
    for(int i=0; i<queue1.size(); i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    int p1 = 0, p2 = 0;
    
    while(p1<(queue1.size()*2) && p2<(queue2.size()*2)){
        if(sum1 > sum2 && p1<queue1.size()){
            sum1 -= queue1[p1];
            sum2 += queue1[p1];
            p1++;
        }
        
        if(sum1 < sum2 && p2<queue2.size()){
            sum2 -= queue2[p2];
            sum1 += queue2[p2];
            p2++;
        }
        
        if(sum1 > sum2 && p1>=queue1.size()){
            sum1 -= queue2[(p1-queue1.size())];
            sum2 += queue2[(p1-queue1.size())];
            p1++;
        }
        
        if(sum1 < sum2 && p2>=queue2.size()){
            sum2 -= queue1[(p2-queue2.size())];
            sum1 += queue1[(p2-queue2.size())];
            p2++;
        }
        
        if(sum1 == sum2) break;
    }
    // 6 14, 7 13, 17 3, 11 9
    if(p1==(queue1.size()*2) || p2==(queue2.size()*2)) return -1;
    else return p1+p2;
}
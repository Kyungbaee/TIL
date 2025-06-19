#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    vector<int> nums;
    while(n>0){
        nums.push_back(n%k);
        n = n/k;
    }
    
    int idx = 0;
    long num = 0;
    vector<long> primes;
    
    for(int n : nums){
        if(n == 0) {
            if(num > 0) primes.push_back(num);
            num = 0;
            idx = -1;
        }
        else num += n * (pow(10, idx));
        idx++;
    }
    if(num > 0) primes.push_back(num);
    

    int answer = 0;
    for(long p : primes) {
        if(p <= 1) continue;
        
        bool chk = false;
        for(long i=2; i<=round(sqrt(p)); i++){
            if(p%i==0) {
                chk = true;
                break;
            }
        }
        if(!chk) answer++;
    }
    return answer;
}
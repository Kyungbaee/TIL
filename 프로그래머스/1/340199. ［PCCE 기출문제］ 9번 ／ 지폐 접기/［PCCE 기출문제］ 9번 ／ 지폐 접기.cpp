#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    sort(wallet.begin(), wallet.end());
    sort(bill.begin(), bill.end());
    
    while(wallet[0]<bill[0] || wallet[1]<bill[1])
    {
        if(wallet[1]<bill[1] || wallet[0]<bill[0])
        {
            bill[1] /= 2;
            answer++;
        }

        if(bill[1]<bill[0])
            sort(bill.begin(), bill.end());

    }
    return answer;
}
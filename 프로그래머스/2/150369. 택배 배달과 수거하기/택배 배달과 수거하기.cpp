#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long delivery[100001];
long long pickup[100001];

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0, total_delivery = 0, total_pickup = 0;
    delivery[n] = deliveries[(n-1)], pickup[n] = pickups[(n-1)];
    for(int i=(n-1); i>0; i--) {
        delivery[i] = deliveries[(i-1)] + delivery[i+1];
        pickup[i] = pickups[(i-1)] + pickup[i+1];
    }
    
    for(int i=n; i>0; i--) {
        while((delivery[i]>total_delivery) || (pickup[i]>total_pickup)) {
            answer += (2*i);
            total_delivery += cap;
            total_pickup += cap;
        }
    }

    return answer;
}
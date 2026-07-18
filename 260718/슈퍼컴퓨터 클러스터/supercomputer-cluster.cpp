#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool calculate(vector<int>& v, long long mid, long long b){
    for(int i=0; i<(int)v.size(); i++){
        long long num = v[i];
        if(mid <= num) return true;

        long long diff = mid - num;
        b -= diff * diff;
        if(b < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    long long b; cin >> b;

    int minN = 1e9+1, maxN = 0;
    vector<int> v;

    while(n--){
        int num; cin >> num;
        minN = min(minN, num); maxN = max(maxN, num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    long long l = minN, r = (long long)maxN + (long long)sqrt((double)b), ans = -1;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        if(calculate(v, mid, b)){
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    cout << ans;

    return 0;
}
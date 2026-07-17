#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int n, q; cin >> n >> q;
    
    for(int i=0; i<n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    while(q--){
        int num; cin >> num;
        auto itr = lower_bound(v.begin(), v.end(), num);
        int idx = itr - v.begin();

        if(v[idx] == num) cout << idx  * (n-idx-1) << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
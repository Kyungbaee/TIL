#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> values[300001];
multiset<int> ms;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int N, K;
    cin >> N >> K;

    for(int i=0; i<N; i++)
        cin >> values[i].second >> values[i].first; // 가격, 무게
    sort(values, values+N);

    for(int i=0; i<K; i++)
    {
        int num;
        cin >> num;
        ms.insert(num);
    }

    long long ans = 0;

    for(int i=N-1; i>=0; i--)
    {
        int m, v;
        tie(v, m) = values[i];
        auto it = ms.lower_bound(m);    // 무게에 맞는 가방
        if(it == ms.end()) continue;
        ans += v;
        ms.erase(it);
    }

    cout << ans;
    return 0;
}
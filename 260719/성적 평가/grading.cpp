#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
vector<vector<int>> scores, temp;
vector<int> ranks, totalScore;

int main() {
    cin.tie(nullptr);

    cin >> N;
    scores.resize(3, vector<int>(N));
    temp.resize(3, vector<int>(N));
    ranks.resize(N, 0);
    totalScore.resize(N, 0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            int num; cin >> num;
            scores[i][j] = num; temp[i][j] = num;
            ranks[j] += num; totalScore[j] += num;
        }
    }

    for(int i=0; i<3; i++) sort(temp[i].begin(), temp[i].end(), greater<int>());

    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            auto itr = lower_bound(temp[i].begin(), temp[i].end(), scores[i][j], greater<int>());
            int idx = itr - temp[i].begin();
            cout << idx+1 << " ";
        }
        cout << "\n";
    }

    sort(totalScore.begin(), totalScore.end(), greater<int>());

    for(int j=0; j<N; j++){
        auto itr = lower_bound(totalScore.begin(), totalScore.end(), ranks[j], greater<int>());
        int idx = itr - totalScore.begin();
        cout << idx+1 << " ";
    }

    return 0;
}

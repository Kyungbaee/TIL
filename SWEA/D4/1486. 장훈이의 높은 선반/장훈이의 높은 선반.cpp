#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++)
	{
		int N, B;
		cin >> N >> B;

        vector<int> H(N);
        int S = 0;
        for (int i = 0; i < N; ++i) {
            cin >> H[i];
            S += H[i];
        }

        vector<bool> dp(S + 1, false);
        dp[0] = true;

        for (int i = 0; i < N; ++i) {
            int h = H[i];
            for (int j = S; j >= 0; --j) {
                if (dp[j] && j + h <= S) {
                    dp[j + h] = true;
                }
            }
        }

        int answer = 200001;
        for (int idx = B; idx <= S; ++idx) {
            if (dp[idx]) {
                answer = idx;
                break;
            }
        }

        cout << "#" << i << " " << (answer - B) << "\n";
	}
	return 0;
}
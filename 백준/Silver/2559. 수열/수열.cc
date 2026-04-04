#include <iostream>

using namespace std;

int nums[100'001];

int main() {
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> nums[i];

	int temp = 0;
	for (int i = 0; i < k; i++) temp += nums[i];

	int answer = temp;
	for (int i = k; i < n; i++) {
		temp += (nums[i] - nums[i - k]);
		if (answer < temp) answer = temp;
	}

	cout << answer;
	return 0;
}
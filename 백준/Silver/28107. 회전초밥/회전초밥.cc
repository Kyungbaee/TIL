#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
queue<int> sushi[200001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k, a;
		cin >> k;
		while (k--) {
			cin >> a;
			sushi[a].push(i);
		}
	}

	int eaten[100001] = { 0 };
	while (m--) {
		int cur_sushi;
		cin >> cur_sushi;
		if (sushi[cur_sushi].empty()) continue;

		int guest = sushi[cur_sushi].front();
		eaten[guest]++;
		sushi[cur_sushi].pop();
	}

	for (int i = 0; i < n; i++) {
		cout << eaten[i] << " ";
	}
	return 0;
}
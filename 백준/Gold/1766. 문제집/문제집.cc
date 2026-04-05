#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int count, value;
};

int inDegree[32'001];
vector<int> outDegree[32'001];
vector<Node> v;

int main() {
	int n, m; cin >> n >> m;
	int from, to;

	while (m--) {
		cin >> from >> to;
		outDegree[from].push_back(to);
		inDegree[to]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int idx = pq.top();
		pq.pop();

		cout << idx << " ";

		for (int nxt : outDegree[idx]) {
			inDegree[nxt]--;
			if (inDegree[nxt] == 0) pq.push(nxt);
		}
	}

	return 0;
}
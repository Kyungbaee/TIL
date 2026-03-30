#include <iostream>
#include <set>
#include <string>

using namespace std;

set<pair<int, string>> s;

int main() {
	int n; cin >> n;

	while (n--) {
		string ss; cin >> ss;
		s.insert({ ss.length(),  ss });
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << (*it).second << "\n";
	}
	return 0;
}
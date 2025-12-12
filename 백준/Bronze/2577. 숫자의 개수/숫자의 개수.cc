#include <iostream>
#include <string>

using namespace std;

int arr[11];

int main() {
	int a, b, c; cin >> a >> b >> c;

	string abc = to_string(a * b * c);

	for (char c : abc)arr[c - '0']++;
	for (int i = 0; i < 10; i++) cout << arr[i] << "\n";

	return 0;
}
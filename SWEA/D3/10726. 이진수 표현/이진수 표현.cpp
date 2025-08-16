#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;

    for (int i = 1; i <= t; i++) {
        int n, m; cin >> n >> m;
        int check = (1 << n) - 1;
        if((check & m) == check)
            cout << "#" << i << " " << "ON" << "\n";
        else
            cout << "#" << i << " " << "OFF" << "\n";
    }
}
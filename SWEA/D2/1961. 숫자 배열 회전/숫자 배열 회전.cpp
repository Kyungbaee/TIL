#include <iostream>

using namespace std;

int board[8][8];

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++)
	{
		int n;
		cin >> n;

		for(int x=1; x<=n; x++) for(int y=1; y<=n; y++) cin >> board[x][y];
		
		cout << "#" << i << "\n";
		for(int rec=0; rec<n; rec++){
			for(int x=n; x>=1; x--) cout << board[x][1+rec];
			cout << " ";
			for(int y=n; y>=1; y--) cout << board[n-rec][y];
			cout << " ";
			for(int x=1; x<=n; x++) cout << board[x][n-rec];
			cout << "\n";
		}
	}
	return 0;
}
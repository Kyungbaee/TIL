#include <iostream>
#include <queue>

using namespace std;

char board[302][302];
int bomb[302][302];
int n;

int bombCount(int x, int y){
	int cnt = 0;
	if(x>1){
		if(board[x-1][y]=='*') cnt++;
		if(y>1 && board[x-1][y-1]=='*') cnt++;
		if(y<n && board[x-1][y+1]=='*') cnt++;
	}
	if(x<n){
		if(board[x+1][y]=='*') cnt++;
		if(y>1 && board[x+1][y-1]=='*') cnt++;
		if(y<n && board[x+1][y+1]=='*') cnt++;
	}
	if(y>1 && board[x][y-1]=='*') cnt++;
	if(y<n && board[x][y+1]=='*') cnt++;

	return cnt;
}

void click(int X, int Y){
	board[X][Y] = '0';
	queue<pair<int, int>> q;
	q.push(make_pair(X, Y));

	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();

		if(x>1){
			if(board[x-1][y]=='.') {
				if(bomb[x-1][y]==0){
					board[x-1][y]='0';
					q.push(make_pair(x-1, y));
				}
				else board[x-1][y] = bomb[x-1][y] + '0';
			}
			if(y>1 && board[x-1][y-1]=='.') {
				if(bomb[x-1][y-1]==0){
					board[x-1][y-1]='0';
					q.push(make_pair(x-1, y-1));
				}
				else board[x-1][y-1] = bomb[x-1][y-1] + '0';
			}
			if(y<n && board[x-1][y+1]=='.') {
				if(bomb[x-1][y+1]==0){
					board[x-1][y+1]='0';
					q.push(make_pair(x-1, y+1));
				}
				else board[x-1][y+1] = bomb[x-1][y+1] + '0';
			}
		}
		if(x<n){
			if(board[x+1][y]=='.'){
				if(bomb[x+1][y]==0){
					board[x+1][y]='0';
					q.push(make_pair(x+1, y));
				}
				else board[x+1][y] = bomb[x+1][y] + '0';
			}
			if(y>1 && board[x+1][y-1]=='.'){
				if(bomb[x+1][y-1]==0){
					board[x+1][y-1]='0';
					q.push(make_pair(x+1, y-1));
				}
				else board[x+1][y-1] = bomb[x+1][y-1] + '0';
			}
			if(y<n && board[x+1][y+1]=='.'){
				if(bomb[x+1][y+1]==0){
					board[x+1][y+1]='0';
					q.push(make_pair(x+1, y+1));
				}
				else board[x+1][y+1] = bomb[x+1][y+1] + '0';
			}
		}
		if(y>1 && board[x][y-1]=='.'){
			if(bomb[x][y-1]==0){
				board[x][y-1]='0';
				q.push(make_pair(x, y-1));
			}
			else board[x][y-1] = bomb[x][y-1] + '0';
		}
		if(y<n && board[x][y+1]=='.'){
			if(bomb[x][y+1]==0){
				board[x][y+1]='0';
				q.push(make_pair(x, y+1));
			}
			else board[x][y+1] = bomb[x][y+1] + '0';
		}
	}
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++)
	{
		cin >> n;
		int answer = 0;
		for(int x=1; x<=n; x++) for(int y=1; y<=n; y++) cin >> board[x][y];
		for(int x=1; x<=n; x++) for(int y=1; y<=n; y++) if(board[x][y]=='.') bomb[x][y] = bombCount(x, y);

		for(int x=1; x<=n; x++) {
			for(int y=1; y<=n; y++){
				if(bomb[x][y]==0 && board[x][y]=='.') {
					click(x, y);
					answer++;
				}
			}
		}

		for(int x=1; x<=n; x++) for(int y=1; y<=n; y++) if(board[x][y]=='.') answer++;
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
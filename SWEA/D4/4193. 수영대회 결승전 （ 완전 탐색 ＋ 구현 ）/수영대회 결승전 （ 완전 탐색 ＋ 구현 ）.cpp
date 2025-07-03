#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int board[16][16], endX, endY, n;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
bool visited[16][16];

int bfs(int X, int Y){
	int answer = 1000000;
	for(int i=0; i<n; i++) fill(visited[i], visited[i]+n, false);
	visited[X][Y] = true;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(X, Y, 0));

	while(!q.empty()){
		auto [x, y, time] = q.front();
		q.pop();

		if(x==endX && y==endY) {
			answer = (answer > time) ? time : answer;
			continue;
		}

		for(int idx=0; idx<4; idx++){
			int nx = x+dx[idx], ny = y+dy[idx];
			if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny] && board[nx][ny] != 1){
				if((board[nx][ny]==2 && (time%3==2)) || board[nx][ny]==0) {
					visited[nx][ny] = true;
					q.push(make_tuple(nx, ny, time+1));
				}else{
					q.push(make_tuple(x, y, time+1));
				}
			}
		}
	}

	return answer;
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++)
	{
		cin >> n;
		for(int x=0; x<n; x++) for(int y=0; y<n; y++) cin >> board[x][y];

		int startX, startY, answer;
		cin >> startX >> startY >> endX >> endY;

		answer = bfs(startX, startY);
		if(answer != 1000000)
			cout << "#" << i << " " << answer << "\n";
		else
			cout << "#" << i << " " << -1 << "\n";
	}
	return 0;
}
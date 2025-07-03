#include <iostream>

using namespace std;

int board[16][16];

int sparyX(int X, int Y, int N, int M){
	int x=X, y=Y, sum=board[X][Y], cnt=1;

	while(x>1 && y>1 && cnt<M){
		x-=1, y-=1;
		sum += board[x][y];
		cnt++;
	}

	x=X, y=Y, cnt=1;
	while(x>1 && y<N && cnt<M){
		x-=1, y+=1;
		sum += board[x][y];
		cnt++;
	}

	x=X, y=Y, cnt=1;
	while(x<N && y<N && cnt<M){
		x+=1, y+=1;
		sum += board[x][y];
		cnt++;
	}

	x=X, y=Y, cnt=1;
	while(x<N && y>1 && cnt<M){
		x+=1, y-=1;
		sum += board[x][y];
		cnt++;
	}
	return sum;
}

int sprayPlus(int X, int Y, int N, int M){
	int x=X, y=Y, sum=board[X][Y], cnt=1;

	while(y>1 && cnt<M){
		y-=1;
		sum += board[x][y];
		cnt++;
	}

	x=X, y=Y, cnt=1;
	while(x>1 && cnt<M){
		x-=1;
		sum += board[x][y];
		cnt++;
	}

	x=X, y=Y, cnt=1;
	while(y<N && cnt<M){
		y+=1;
		sum += board[x][y];
		cnt++;
	}

	x=X, y=Y, cnt=1;
	while(x<N && cnt<M){
		x+=1;
		sum += board[x][y];
		cnt++;
	}

	return sum;
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++)
	{
		int n, m, answer=0;
		cin >> n >> m;

		for(int x=1; x<=n; x++) for(int y=1; y<=n; y++) cin >> board[x][y];

		for(int x=1; x<=n; x++) {
			for(int y=1; y<=n; y++){
				int sprayType1 = sparyX(x, y, n, m);
				int sprayType2 = sprayPlus(x, y, n, m);
				
				if(answer < sprayType1) answer = sprayType1;
				if(answer < sprayType2) answer = sprayType2;
			}
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
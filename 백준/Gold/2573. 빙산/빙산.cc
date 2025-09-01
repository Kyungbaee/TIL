#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int N, M, arr[301][301], alive, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int visited[301][301];

/*
	N * M 농장 ( N, M <= 75 )
	- 각 칸은 농작물이 가진 수분량 (= 0은 메마른 땅) ( <= 최대 10 )
	- 가뭄은 농작물의 생명력을 빠르게 소모
	- 메마른 땅과 많이 접할수록 더 빨리 말라 죽는다.
	- 각 칸의 동작물은 1년마다 동서남북 메마른 땅의 개수만큼 수분량 줄어듬

	밭이 독립된 구역으로 나눠지는 시점이 언제인가?
	- 모든 농작물이 메마를 때까지 구역이 나뉘지 않는다면, 0을 출력
*/

void bfs(int x, int y, int GroupNumber) {
	visited[x][y] = GroupNumber;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0 && arr[nx][ny]>0) {
				visited[nx][ny] = GroupNumber;
				q.push({ nx,ny });
			}
		}
	}
}

bool IsSeparate() {
	memset(visited, 0, sizeof(visited));
	int GroupNumber = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0 && visited[i][j] == 0 && GroupNumber == 1) {
				bfs(i, j, GroupNumber);
				GroupNumber++;
			}
			else if (arr[i][j] > 0 && visited[i][j] == 0 && GroupNumber != 1) {
				return true;
			}
		}
	}
	return false;
}

void AfterYear() {
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) continue;

			int curWater = arr[i][j];
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d], ny = j + dy[d];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0) {
					curWater--;
				}
			}

			v.push_back({ i, j, curWater });
		}
	}

	for (tuple<int, int, int> t : v) {
		int nx, ny, nWater;
		tie(nx, ny, nWater) = t;

		arr[nx][ny] = max(0, nWater);
		if (arr[nx][ny] == 0) {
			alive--;
		}
	}
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				alive++;
			}
		}
	}
	int Year = 0;

	while (true) {
		if (alive == 0) {
			cout << 0;
			break;
		}
		if (IsSeparate()) {
			cout << Year;
			break;
		}
		AfterYear();
		Year++;
	}

	return 0;
}
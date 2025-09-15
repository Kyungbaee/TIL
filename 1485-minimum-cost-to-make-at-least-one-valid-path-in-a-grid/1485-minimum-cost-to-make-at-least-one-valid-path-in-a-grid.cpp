class Solution {
public:
    // 우, 좌, 하, 상
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, M, N, cost = INT_MAX;
    bool visited[101][101];
    using T = tuple<int, int, int>;

    bool isBoundary(int x, int y){
        if(x >= 0 && x < M && y >= 0 && y < N) return true;
        return false;
    }

    bool isNotCycle(int dir1, int dir2){
        if(dir1 == 0 && dir2 == 1) return false;
        if(dir2 == 0 && dir1 == 0) return false;
        if(dir1 == 2 && dir2 == 3) return false;
        if(dir1 == 3 && dir2 == 2) return false;
        return true;
    }

    int minCost(vector<vector<int>>& grid) {
        // for(int i=0; i<101; i++)
        //     fill(visited[i], visited[i]+101, INT_MAX);
        M = grid.size(), N = grid[0].size();

        visited[0][0] = false;
        priority_queue<T, vector<T>, greater<T>> q;
        q.push({0, 0, 0});


        while(!q.empty()){
            T t = q.top();
            q.pop();

            int cnt, x, y;
            tie(cnt, x, y) = t;
            if(visited[x][y]) continue;
            visited[x][y] = true;
            if(cnt >= N+M-1) return N+M-1;

            if(x == M-1 && y == N-1){
                return cnt;
            }

            for(int i : {0, 2, 1, 3}){
                int nx = x+dx[i], ny = y+dy[i];

                if(isBoundary(nx, ny) && !visited[nx][ny]){
                    if(i == grid[x][y]-1) {
                        q.push({cnt, nx, ny});
                    }
                    else {
                        q.push({cnt+1, nx, ny});
                    }
                }
            }

        }
        return cost;
    }
};
class Solution {
public:
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    bool visited[51][51];

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = int(grid.size()), n = int(grid[0].size());
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({grid[0][0],0,0});
        visited[0][0] = true;

        while(!q.empty()){
            int value, x, y;
            tie(value, x, y) = q.top();
            q.pop();

            if(x==(m-1) && y==(n-1)) return true;

            for(int i=0; i<4; i++){
                int mx = x+dx[i], my = y+dy[i];

                if(mx>=0 && mx<m && my>=0 && my<n && value+grid[mx][my] < health && !visited[mx][my]){
                    q.push({value+grid[mx][my], mx, my});
                    visited[mx][my] = true;
                }
            }
        }
        
        return false;
    }
};
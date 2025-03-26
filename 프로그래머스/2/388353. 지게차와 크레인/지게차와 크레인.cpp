#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool visited[51][51];

void gCar(char target, vector<string> &storage, int n, int m){
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    vector<pair<int, int>> delPoint;
    
    for(int idx=0; idx<n; idx++)
        fill(visited[idx], visited[idx]+m, false);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i!=0 && i!=n-1 && j!=0 && j!=m-1) continue;
            
            if(storage[i][j]==target) delPoint.push_back(make_pair(i,j));
            else if(storage[i][j] == ' '){
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = true;

                while(!q.empty()){
                    pair<int, int> xy = q.front();
                    q.pop();
                    
                    int x = xy.first, y = xy.second;

                    for(int dir=0; dir<4; dir++){
                        int nx = x+dx[dir], ny = y+dy[dir];
                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

                        if(storage[nx][ny]==target && !visited[nx][ny]) {
                            delPoint.push_back(make_pair(nx,ny));
                            visited[nx][ny] = true;
                        }
                        if(storage[nx][ny]==' ' && !visited[nx][ny])
                        {
                            q.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    for(pair<int, int> point : delPoint)
        storage[point.first][point.second] = ' ';
}

void crain(char target, vector<string> &storage, int n, int m){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(storage[i][j] == target) storage[i][j] = ' ';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].size();
    
    for(string cmd : requests)
    {
        if(cmd.size()==1)
            gCar(cmd[0], storage, n, m);
        else crain(cmd[0], storage, n, m);
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(storage[i][j] != ' ') answer++;
    }
    return answer;
}
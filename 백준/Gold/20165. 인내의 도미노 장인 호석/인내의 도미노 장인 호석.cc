#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, r;
int original[102][102];
int domino[102][102];
int answer;

vector<pair<int, int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void down(int x, int y, char D){
    int dx, dy;
    if(D=='N') tie(dx, dy) = dir[0];
    else if(D=='E') tie(dx, dy) = dir[1];
    else if(D=='S') tie(dx, dy) = dir[2];
    else if(D=='W') tie(dx, dy) = dir[3];

    int nx=x+dx, ny=y+dy, cnt=original[x][y]-1;
    while(cnt--)
    {
        // if(nx>0 && nx<=n && ny>0 && ny<=m && !domino[nx][ny])
        if(nx>0 && nx<=n && ny>0 && ny<=m)
        {
            if(cnt < original[nx][ny]-1 && !domino[nx][ny]) cnt=original[nx][ny]-1;
            if(!domino[nx][ny])
            {
                domino[nx][ny]=1;
                answer++;
            }
            nx=nx+dx, ny=ny+dy;
        }
        else break;
    }
}

void up(int x, int y){
    domino[x][y]=0;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> n >> m >> r;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> original[i][j];
        }
    }

    while(r--)
    {
        int x, y;
        char D;
        cin >> x >> y >> D;

        domino[x][y]=1;
        answer++;
        down(x, y, D);

        cin >> x >> y;
        up(x, y);
    }

    cout << answer << "\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(domino[i][j]==1) cout << 'F' << " ";
            if(domino[i][j]==0) cout << 'S' << " ";
        }
        cout << "\n";
    }
    return 0;
}
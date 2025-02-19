#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> plan[1001];
int calendar[1001][367];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음
    
    int n;
    cin >> n;

    int max_length = 0;
    for(int i=0; i<n; i++)
    {
        int st, ed;
        cin >> st >> ed;

        max_length = max(max_length, ed);
        plan[i] = make_pair(st, ed);
    }

    sort(plan, plan+n, [](pair<int, int> L, pair<int, int> R){
        return L.first != R.first ? L.first < R.first : L.second > R.second;
    });

    int max_depth = 0;
    for(int i=0; i<n; i++)
    {
        int st=plan[i].first, ed=plan[i].second;
        int chk = 0;

        for(int depth=1; depth<1001; depth++)
        {
            if(!calendar[depth][st])
            {
                chk = depth;
                break;
            }
        }

        for(int day=st; day<=ed; day++)
            calendar[chk][day]=1;
    }

    int area = 0, min_y = 0, max_x = 0, max_y = 0;

    for(int i=1; i<=max_length+1; i++)
    {
        if(!min_y && calendar[1][i]) min_y = i;

        int chk = 1;
        for(int j=1; j<1001; j++)
        {
            if(calendar[j][i])
            {
                chk = 0;
                max_x = max(max_x, j);
            }
        }

        if(chk)
        {
            area += (max_y-min_y+1)*max_x;
            min_y = 0, max_x = 0, max_y = 0;
        }
        else max_y = max(max_y, i);
    }
    
    cout << area;
    return 0;

    /* 
    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx BFS xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

    for(int i=0; i<n; i++)
    {
        int st = plan[i].first;
        
        if(!visitied[1][st])
        {
            max_x = 0, max_y = 0;
            BFS(1, st);
            area += (max_y-st+1) * max_x;
        }
    }
    */
}


/*
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int max_x;
int max_y;

bool visitied[366][366];

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visitied[x][y] = true;
    
    while(!q.empty()){
    	int cur_x = q.front().first, cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur_x+dx[i], ny = cur_y+dy[i];

            if(calendar[nx][ny] && !visitied[nx][ny] && nx >= 1 && ny >= 1)
            {
                max_x = max(max_x, nx);
                max_y = max(max_y, ny);

                q.push(make_pair(nx, ny));
                visitied[nx][ny] = true;
            }
        }   
    }
}
*/
#include <iostream>
#include <vector>

using namespace std;

int lab[2001][2001];
bool chk_lab[2001][2001];
int n, m;
vector<pair<int, int>> airs;

void search(int x, int y)
{
    pair<int, int> dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    chk_lab[x][y]=true;

    for(int i=0; i<4; i++)
    {
        int idx = i;
        int dx = dir[idx].first, dy = dir[idx].second;

        int nx = x+dx, ny = y+dy;
        while(nx>0 && nx<=n && ny>0 && ny<=m)
        {
            chk_lab[nx][ny]=true;
            if(lab[nx][ny]==1)
            {
                if(idx==1 || idx==3) break;
                // if(idx==1 || idx==3) idx = (idx+2)%4;
            }
            else if(lab[nx][ny]==2)
            {
                if(idx==0 || idx==2) break;
                // if(idx==0 || idx==2) idx = (idx+2)%4;
            }
            else if(lab[nx][ny]==3)
            {
                // 0->1, 1->0, 2->3, 3->2
                if(idx==0 || idx==1) idx = (idx+1)%2;
                else if(idx==2) idx++;
                else if(idx==3) idx--;
            }
            else if(lab[nx][ny]==4)
            {
                // 0->3, 1->2, 2->1, 3->0
                if(idx==0 || idx==3) idx = 4-(idx+1);
                else if(idx==1) idx++;
                else if(idx==2) idx--;
            }

            dx = dir[idx].first, dy = dir[idx].second;
            nx = nx+dx, ny = ny+dy;
            // if(nx==x && ny==y) break;
            if(lab[nx][ny]==9) break;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> lab[i][j];
            if(lab[i][j] == 9) airs.push_back(make_pair(i, j));
        }
    }

    for(pair<int, int> air : airs)
    {
        search(air.first, air.second);
    }

    int answer=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(chk_lab[i][j]) answer++;
        }
    }

    cout << answer;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
int cnt[1001];
int nums[1001];
int answer[1001];

int solve(int n)
{
    queue<int> q;
    int idx=0;

    for(int i=1; i<=n; i++)
        if(cnt[i]==0) q.push(i);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        answer[idx++] = cur;

        for(int next : adj[cur])
        {
            cnt[next]--;
            if(cnt[next]==0) q.push(next);
        }
    }

    return idx;
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int rec, num;
        cin >> rec;
        for(int i=0; i<rec; i++)
        {
            cin >> num;
            nums[i]=num;
        }

        for(int i=0; i<rec-1; i++)
        {
            adj[nums[i]].push_back(nums[i+1]);
            cnt[nums[i+1]]++;
        }
    }

    if(solve(n)==n)
    {
        for(int i=0; i<n; i++) cout << answer[i] << "\n";
    }
    else cout << "0";


    return 0;
}
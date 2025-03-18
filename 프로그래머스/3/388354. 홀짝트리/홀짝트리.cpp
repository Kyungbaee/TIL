#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> m[1000001];
bool visited[1000001];

int check(int num, int size, int cur){
    // cout << num << " " << size << " " << cur << "\n";
    if(num%2 == size%2) {
        if(cur==2)
        {
            return -1;
        }
        return 1;
    }
    else if(num%2 != size%2) {
        if(cur==1)
        {
            return -1;
        }
        return 2;
    }
}

int bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r]=true;
    int checkNode = 0;
    checkNode = check(r, m[r].size(), checkNode);
    
    while(!q.empty())
    {
        int nxt = q.front();
        q.pop();
        
        for(int mm : m[nxt])
        {
            if(!visited[mm])
            {
                q.push(mm);
                visited[mm]=true;
                checkNode = check(mm, m[mm].size()-1, checkNode);
                if(checkNode==-1) return -1;
            }
        }
    }
    
    return checkNode;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = {0,0};
    
    for(auto edge : edges)
    {
        m[edge[0]].push_back(edge[1]);
        m[edge[1]].push_back(edge[0]);
    }
    
    for(int root : nodes)
    {
        // cout << root << " " << bfs(root) << "\n";
        int idx = bfs(root);
        if(idx != -1) answer[idx-1]++;
        fill(visited, visited+1000001, false);
    }
    
    return answer;
}
class Solution {
public:
    vector<int> connect[51];
    int value[51], answer;
    bool visited[51];

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        for(int i=1; i<=n; i++) value[i] = i;

        for(vector<int> edge : edges){
            connect[edge[0]+1].push_back(edge[1]+1);
            connect[edge[1]+1].push_back(edge[0]+1);
            value[edge[0]+1] += edge[1]+1;
            value[edge[1]+1] += edge[0]+1;
        }

        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            visited[i] = true;

            bool flag = true;
            for(int nxt : connect[i]){
                visited[nxt] = true;
                if(value[i] != value[nxt] || int(connect[i].size()) != int(connect[nxt].size())) {
                    flag = false;
                    continue;
                }
            }

            if(flag) answer++;
        }

        return answer;
    }
};
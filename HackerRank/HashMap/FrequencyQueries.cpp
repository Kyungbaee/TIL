// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> result;
    unordered_map<int, int> um;
    unordered_map<int, int> um_cnt;
        
    for(vector<int> query : queries){
        int cmd = query[0], num = query[1];
        
        if(cmd == 1) {
            int upCnt = um[num];
            um_cnt[upCnt]--;
            um_cnt[upCnt+1]++;
            um[num]++;
        }
        else if(cmd == 2){
            if(um[num]>0) {
                int upCnt = um[num];
                um_cnt[upCnt]--;
                um_cnt[upCnt-1]++;
                um[num]--;
            }
        }
        else if(cmd == 3){
            if(um_cnt[num]>0) result.push_back(1);
            else result.push_back(0);
        }
    }
    
    return result;
}

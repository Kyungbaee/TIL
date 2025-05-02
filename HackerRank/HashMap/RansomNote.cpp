void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> um;
    
    for(string s : magazine) um[s]++;

    for(string s : note){
        if(um[s]) um[s]--;
        else {
            cout << "No\n";
            return ;
        }
    }
    
    cout << "Yes\n";
}

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

string table[51][51];
pair<int, int> merge_table[51][51];
vector<string> answer;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

pair<int, int> findParent(int r, int c){
    if (make_pair(r, c) == merge_table[r][c]) return make_pair(r, c);
    return findParent(merge_table[r][c].first, merge_table[r][c].second);
}

void update(int r, int c, string value){
    tie(r, c) = findParent(r, c);
    table[r][c] = value;
    return;
}

void merge(int r1, int c1, int r2, int c2){
    tie(r1, c1) = findParent(r1, c1);
    tie(r2, c2) = findParent(r2, c2);
    
    if(r1==r2 && c1==c2) return;
    string value1 = table[r1][c1], value2 = table[r2][c2];
    
    if(value1.empty() && !value2.empty()) {
        merge_table[r1][c1] = make_pair(r2, c2);
        
        for(int i=1; i<=50; i++) for(int j=1; j<=50; j++)
            if(merge_table[i][j] == make_pair(r1, c1)) merge_table[i][j] = make_pair(r2, c2);
    }
    else {
        merge_table[r2][c2] = make_pair(r1, c1);
        table[r2][c2].clear();
        
        for(int i=1; i<=50; i++) for(int j=1; j<=50; j++)
            if(merge_table[i][j] == make_pair(r2, c2)) merge_table[i][j] = make_pair(r1, c1);
    }
    return;
}

void unmerge(int r, int c){
    int r1 = r, c1 = c;
    tie(r1, c1) = findParent(r, c);
    string value = table[r1][c1];
    
    for(int i=1; i<=50; i++) for(int j=1; j<=50; j++)
        if(merge_table[i][j] == make_pair(r1, c1)) {
            merge_table[i][j] = make_pair(i, j);
            table[i][j].clear();
        }
    
    table[r][c] = value;
    return;
}

void print(int r, int c){
    tie(r, c) = findParent(r, c);
    string value = table[r][c];
    
    if(!value.empty()) answer.push_back(table[r][c]);
    else answer.push_back("EMPTY");
    return;
}

vector<string> solution(vector<string> commands) {
    for(int i=1; i<=50; i++) for(int j=1; j<=50; j++) merge_table[i][j] = {i, j};
    
    for(string s : commands){
        vector<string> cmd = split(s, " ");
        
        if(cmd[0] == "UPDATE"){
            if(cmd.size() > 3) update(stoi(cmd[1]), stoi(cmd[2]), cmd[3]);
            else{
                for(int i=1; i<=50; i++) for(int j=1; j<=50; j++)
                    if(table[i][j] == cmd[1]) update(i, j, cmd[2]);
            }
        }
        
        if(cmd[0] == "MERGE"){
            int r1 = stoi(cmd[1]), c1 = stoi(cmd[2]), r2 = stoi(cmd[3]), c2 = stoi(cmd[4]);
            merge(r1,c1,r2,c2);   
        }
        
        if(cmd[0] == "UNMERGE"){
            int r = stoi(cmd[1]), c = stoi(cmd[2]);
            unmerge(r,c);
        }
        
        if(cmd[0] == "PRINT"){
            int r = stoi(cmd[1]), c = stoi(cmd[2]);
            print(r,c);
        }
    }
    
    return answer;
}
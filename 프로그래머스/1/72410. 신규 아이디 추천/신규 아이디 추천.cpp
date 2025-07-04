#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1 단계
    for(int i=0; i<new_id.length(); i++)
        if(new_id[i]>='A' && new_id[i]<='Z') new_id[i] = char(new_id[i]+('a'-'A'));
    
    // 2 단계
    vector<int> removeList;
    for(int i=0; i<new_id.length(); i++){
        if(new_id[i]>='0' && new_id[i]<='9') continue;
        else if(new_id[i]>='a' && new_id[i]<='z') continue;
        else if(new_id[i]=='-' || new_id[i]=='_' || new_id[i]=='.') continue;
        else removeList.push_back(i);
    }
    
    while(!removeList.empty()){
        int idx = removeList.back();
        removeList.pop_back();
        new_id.erase(new_id.begin()+idx);
    }
    
    // 3 단계
    for(int i=1; i<new_id.length(); i++)
        if(new_id[i]=='.' && new_id[i-1]=='.') removeList.push_back(i);
    
    while(!removeList.empty()){
        int idx = removeList.back();
        removeList.pop_back();
        new_id.erase(new_id.begin()+idx);
    }
    
    // 4 단계
    if(new_id.length()>0 && new_id[0]=='.') removeList.push_back(0);
    if(new_id.length()>1 && new_id[new_id.length()-1]=='.') removeList.push_back(new_id.length()-1);
    
    while(!removeList.empty()){
        int idx = removeList.back();
        removeList.pop_back();
        new_id.erase(new_id.begin()+idx);
    }
    
    // 5 단계
    if(new_id.length()==0) new_id = "a";
    
    // 6 단계
    if(new_id.length()>15 && new_id[14] == '.') removeList.push_back(14);
    for(int i=15; i<new_id.length(); i++) removeList.push_back(i);
    
    while(!removeList.empty()){
        int idx = removeList.back();
        removeList.pop_back();
        new_id.erase(new_id.begin()+idx);
    }
    
    // 7 단계
    while(new_id.length()<=2){
        new_id += new_id[new_id.length()-1];
    }
    
    return new_id;
}
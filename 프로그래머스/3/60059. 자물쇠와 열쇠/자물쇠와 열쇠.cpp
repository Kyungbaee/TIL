#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> Key;
int hole = 0, M = 0;

void pulling(){
    int minX = 41, minY = 41;
    
    for(int i=0; i<Key.size(); i++){
        int x=Key[i].first, y=Key[i].second;
        if(x<minX) minX = x;
        if(y<minY) minY = y;
    }
    for(int i=0; i<Key.size(); i++){
        Key[i].first -= minX;
        Key[i].second -= minY;
    }
}

void rotation(){
    for(int i=0; i<Key.size(); i++){
        int temp = Key[i].first;
        Key[i].first = -Key[i].second;
        Key[i].second = temp;
    }
    
    pulling();
}

bool open(vector<vector<int>> lock){
    int N = lock.size();
    for(int i=-M; i<int(lock.size()); i++){
        for(int j=-M; j<int(lock[0].size()); j++){
            int cnt = 0;
            bool chk = true;

            for(pair<int, int> p : Key){
                int dx = p.first, dy = p.second;
                if(i+dx>=N || j+dy >= N || i+dx<0 || j+dy<0) continue;
                if(lock[i+dx][j+dy] == 1) {
                    chk = false;
                    break;
                }else if(lock[i+dx][j+dy]==0){
                    cnt++;
                }
            }
            if(chk && hole == cnt) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock[i].size(); j++)
            if(lock[i][j]==0) hole++;
    }
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key[0].size(); j++){
            if(key[i][j] == 1)
                Key.push_back(make_pair(i, j));
        }
    }

    // 0 degree
    pulling();
    if(open(lock)) return true;

    // 90 degree
    rotation();
    if(open(lock)) return true;
       
    // 180 degree
    rotation();
    if(open(lock)) return true;
       
    // 270 degree
    rotation();
    if(open(lock)) return true;
       
    return false;
}
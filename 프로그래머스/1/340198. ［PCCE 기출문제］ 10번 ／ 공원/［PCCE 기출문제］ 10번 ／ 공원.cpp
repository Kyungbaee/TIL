#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sort(mats.begin(), mats.end());
    
    for(int i=0; i<mats.size(); i++)
    {
        int n = mats[i];
        
        for(int h=0; h<park.size(); h++)
        {
            for(int w=0; w<park[0].size(); w++)
            {
                if(park[h][w] != "-1") continue;
                bool chk = true;
                for(int dx=0; dx<n; dx++){
                    for(int dy=0; dy<n; dy++)
                    {
                        if(((h+dx)>=park.size() || (w+dy)>=park[0].size()) || \
                           park[h+dx][w+dy]!="-1"){
                            chk = false;
                            break;
                        }
                    }
                    if(!chk) break;   
                }
                if(chk) answer = n;
            }
        }
    }
    
    return answer;
}
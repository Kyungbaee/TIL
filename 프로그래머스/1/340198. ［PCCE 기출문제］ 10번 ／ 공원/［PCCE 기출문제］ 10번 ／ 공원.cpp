#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chk(vector<vector<string>> park, int h, int w, int n)
{
    bool chk = true;
    for(int dx=0; dx<n; dx++){
        for(int dy=0; dy<n; dy++)
        {
            if(((h+dx)>=park.size() || (w+dy)>=park[0].size()) || \
               park[h+dx][w+dy]!="-1"){
                return -1;
            }
        }
    }
    return n;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end());
    int answer = -1;
    
    for(int i=0; i<mats.size(); i++)
    {
        int n = mats[i];
        
        for(int h=0; h<park.size(); h++)
        {
            for(int w=0; w<park[0].size(); w++)
            {
                if(park[h][w] != "-1") continue;
                answer = max(answer, chk(park,h,w,n));
            }
        }
    }
    return answer;
}
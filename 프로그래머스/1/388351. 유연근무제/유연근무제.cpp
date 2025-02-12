#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0; i<schedules.size(); i++)
    {
        int goal = ((schedules[i]/100 + (schedules[i]%100+10)/60)*100) + (schedules[i]%100+10)%60;
        int start_cnt = startday-1, chk=1;
        
        for(int j=0; j<timelogs[i].size(); j++)
        {
            int cmp_time = timelogs[i][j];
            if(start_cnt%7 < 5)
            {
                if(goal < cmp_time)
                {
                    chk=0;
                    break;
                }
            }
            start_cnt++;
        }
        
        if(chk) answer++;
    }
    return answer;
}
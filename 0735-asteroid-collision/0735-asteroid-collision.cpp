class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> temp = asteroids, answer;

        vector<int> positive;
        queue<int> negative;
        int pCount = 0, nCount = 0;

        for(int idx=0; idx<int(temp.size()); idx++){
            // 우측으로 향하는 행성 모아두기
            if(temp[idx] > 0 && negative.empty()) positive.push_back(temp[idx]);
            // 좌측으로 향하는 행성은 패스
            else if(temp[idx] < 0 && positive.empty()) answer.push_back(temp[idx]);
            // 충돌 발생
            else{
                // 충돌할 좌측방향 행성 모으기
                if(temp[idx] < 0 && !positive.empty()) negative.push(temp[idx]);
                // 계산
                else if(temp[idx] > 0 && !negative.empty()){
                    while(!positive.empty() && !negative.empty()){
                        int leftTemp = positive.back(), rightTemp = abs(negative.front());
                        if(leftTemp > rightTemp){
                            negative.pop();
                        }
                        else if(leftTemp == rightTemp){
                            positive.pop_back();
                            negative.pop();
                        }
                        else if(leftTemp < rightTemp){
                            positive.pop_back();
                        }
                    }

                    while(!negative.empty()) {
                        answer.push_back(negative.front());
                        negative.pop();
                    }
                    positive.push_back(temp[idx]);
                }
            }
        }

        while(!positive.empty() && !negative.empty()){
            int leftTemp = positive.back(), rightTemp = abs(negative.front());
            if(leftTemp > rightTemp){
                negative.pop();
            }
            else if(leftTemp == rightTemp){
                positive.pop_back();
                negative.pop();
            }
            else if(leftTemp < rightTemp){
                positive.pop_back();
            }
        }

        while(!negative.empty()) {
            answer.push_back(negative.front());
            negative.pop();
        }
        if(!positive.empty()) {
            answer.insert(answer.end(), positive.begin(), positive.end());
            positive.clear();
        }
        return answer;
    }
};
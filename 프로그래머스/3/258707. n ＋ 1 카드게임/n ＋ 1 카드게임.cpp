#include <string>
#include <vector>
#include <set>

using namespace std;

bool MatchCards(set<int>& cards1, set<int>& cards2, int target)
{
    for (int a : cards1)
    {
        auto it = cards2.find(target - a);
        if (it != cards2.end())
        {
            cards1.erase(a);
            cards2.erase(*it);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) 
{
    set<int> hands, draws;
    int answer = 1, size = cards.size();
    
    for (int i = 0; i < size / 3; i++)
        hands.insert(cards[i]);
    
    for (int i = size / 3; i < size; i+=2)
    {
        draws.insert(cards[i]);
        draws.insert(cards[i+1]);
        
        // 손에 있는 패로 목표 수를 만들 수 있는지
        if (MatchCards(hands, hands, size+1))
        {
            // 코인 소모 없음
        }
        else if (coin >= 1 && MatchCards(hands, draws, size+1))
        {
            coin -= 1;
        }
        else if (coin >= 2 && MatchCards(draws, draws, size+1))
        {
            coin -= 2;
        }
        else
            break;
        answer++;
    }
    
    return answer;
}
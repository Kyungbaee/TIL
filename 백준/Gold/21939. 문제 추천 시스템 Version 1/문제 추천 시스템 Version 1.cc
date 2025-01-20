#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    multiset<pair<int, int>> U_ms;
    multiset<pair<int, int>> D_ms;
    map<int, int> numToLevel;

    int n, m;
    cin >> n;

    while(n--)
    {
        int s_num, s_level;
        cin >> s_num >> s_level;

        U_ms.insert(make_pair(s_level, s_num));
        D_ms.insert(make_pair(-s_level, -s_num));
        numToLevel.insert(make_pair(s_num, s_level));
    }

    cin >> m;
    while(m--)
    {
        string cmd;
        cin >> cmd;
        int num, level;

        if(cmd=="add")
        {
            cin >> num >> level;
            U_ms.insert(make_pair(level, num));
            D_ms.insert(make_pair(-level, -num));
            numToLevel[num] = level;
        }
        else if(cmd=="recommend")
        {
            cin >> num;
            if(num == 1)
                cout << (*prev(U_ms.end())).second << "\n";
            else
                cout << (*prev(D_ms.end())).second * -1 << "\n";
        }
        else if(cmd=="solved")
        {
            cin >> num;
            level = numToLevel.at(num);
            U_ms.erase(U_ms.find(make_pair(level, num)));
            D_ms.erase(D_ms.find(make_pair(-level, -num)));
            numToLevel.erase(num);
        }
    }   

    // priority_queue<pair<int, int>> U_pq;
    // priority_queue<pair<int, int>> D_pq;

    // int n, m;
    // cin >> n;

    // while(n--)
    // {
    //     int s_num, s_level;
    //     cin >> s_num >> s_level;

    //     U_pq.push(make_pair(s_level, s_num));
    //     D_pq.push(make_pair(-s_level, s_num));
    // }

    // cin >> m;

    // while(m--)
    // {
    //     string cmd;
    //     int num, level;

    //     if(cmd=="add")
    //     {
    //         cin >> num >> level;
    //         U_pq.push(make_pair(level, num));
    //         D_pq.push(make_pair(-level, num));
    //     }
    //     else if(cmd=="recommand")
    //     {
    //         cin >> num;
    //         if(num == 1)
    //             cout << U_pq.top().second << "\n";
    //         else
    //             cout << D_pq.top().second << "\n";
    //     }
    //     else if(cmd=="solved")
    //     {
    //         cin >> num;
    //         // 우선순위 큐는 사용 불가
    //     }
    // }   
    return 0;
}
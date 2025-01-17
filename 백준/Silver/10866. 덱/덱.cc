#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    deque<int> dq;
    vector<string> cmdList = {"push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back"};

    int n;
    cin >> n;

    while(n--)
    {
        string cmd;
        cin >> cmd;
        int num=0;

        if(cmd==cmdList[0])
        {
            cin >> num;
            dq.push_front(num);
        }
        else if(cmd==cmdList[1])
        {
            cin >> num;
            dq.push_back(num);
        }
        else if(cmd==cmdList[2])
        {
            if(dq.empty()) cout << "-1" << "\n";
            else
            {
                num = dq.front();
                dq.pop_front();
                cout << num << "\n";
            }
        }
        else if(cmd==cmdList[3])
        {
            if(dq.empty()) cout << "-1" << "\n";
            else
            {
                num = dq.back();
                dq.pop_back();
                cout << num << "\n";
            }
        }
        else if(cmd==cmdList[4])
        {
            cout << dq.size() << "\n";
        }
        else if(cmd==cmdList[5])
        {
            if(dq.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(cmd==cmdList[6])
        {
            if(dq.empty()) cout << "-1" << "\n";
            else
            {
                num = dq.front();
                cout << num << "\n";
            }
        }
        else if(cmd==cmdList[7])
        {
            if(dq.empty()) cout << "-1" << "\n";
            else
            {
                num = dq.back();
                cout << num << "\n";
            }
        }

    }

    return 0;
}
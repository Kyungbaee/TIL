#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    stack<int> stk;
    int n;
    cin >> n;

    while(n--)
    {
        string cmd;
        cin >> cmd;
        int num = 0;

        if(cmd=="push")
        {
            cin >> num;
            stk.push(num);
        }
        else if(cmd=="pop")
        {
            if(stk.empty()) cout << "-1" << "\n";
            else
            {
                num = stk.top();
                stk.pop();
                cout << num << "\n";
            }
        }
        else if(cmd=="size")
        {
            cout << stk.size() << "\n";
        }
        else if(cmd=="empty")
        {
            if(stk.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(cmd=="top")
        {
            if(stk.empty()) cout << "-1" << "\n";
            else cout << stk.top() << "\n";
        }
    }

    return 0;
}
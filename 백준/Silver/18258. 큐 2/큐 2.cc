#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    queue<int> q;
    int n;
    cin >> n;

    while(n--)
    {
        int num=0;
        string s;
        cin >> s;

        if (s=="push")
        {
            cin >> num;
            q.push(num);
        }
        else if (s=="pop")
        {
            if(q.empty()) cout << "-1" << "\n";
            else
            {            
                num = q.front();
                q.pop();
                cout << num << "\n";
            }

        }
        else if(s=="size")
        {
            cout << q.size() << "\n";
        }
        else if(s=="empty")
        {
            if(q.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(s=="front")
        {
            if(q.empty()) cout << "-1" << "\n";
            else cout << q.front() << "\n";
        }
        else if(s=="back")
        {
            if(q.empty()) cout << "-1" << "\n";
            else cout << q.back() << "\n";
        }
    }

    return 0;
}
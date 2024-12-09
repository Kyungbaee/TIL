#include <iostream>
#include <set>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int T;
    cin >> T;

    while(T--)
    {
        multiset<int> ms;
        int k;
        cin >> k;

        while(k--)
        {
            char command;
            int num;

            cin >> command >> num;

            if (command=='I') ms.insert(num);
            else
            {
                if(ms.empty()) continue;
                else if(num==1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }
        }

        if(ms.empty()) cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
    }


    return 0;
}
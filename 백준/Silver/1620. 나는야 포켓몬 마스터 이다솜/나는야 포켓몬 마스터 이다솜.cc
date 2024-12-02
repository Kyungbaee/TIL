#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    //unordered_set<string> s;
    //unordered_multiset<int> ms;
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++)
    {
        string name;
        cin >> name;
        m1[name] = i;
        m2[i] = name;
    }


    for(int i=0; i<M; i++)
    {
        string quiz;
        cin >> quiz;

        if(isdigit(quiz[0]))
            cout << m2[stoi(quiz)] << '\n';
        else
            cout << m1[quiz] << '\n';
    }

    return 0;
}
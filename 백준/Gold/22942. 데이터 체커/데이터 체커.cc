#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;
    vector<pair<int, int>> circles(n);

    while(n--)
    {
        int x, r;
        cin >> x >> r;

        circles[n] = make_pair(x-r, x+r);
    }

    sort(circles.begin(), circles.end(), [](pair<int,int> left, pair<int,int> right) {
        return left.first != right.first ? left.first < right.first : left.second < right.second;
    });

    bool is_valid = true;
    vector<int> end_stack;

    // circle : <1, 9>, end_stack : 9
    // circle : <2, 4>, end_stack : 9, 4
    // circle : <5, 7>, end_stack : 9, 7
    // circle : <10, 16>, end_stack : 10

    for(auto circle : circles)
    {
        while(!end_stack.empty() && end_stack.back() < circle.first) // 비교할 우측 값만 남겨 놓기
        {
            end_stack.pop_back();
        }

        if(!end_stack.empty() && circle.first <= end_stack.back() && end_stack.back() <= circle.second) // 겹치는 경우
        {
            is_valid = false;
            break;
        }

        end_stack.push_back(circle.second);
    }

    if (is_valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
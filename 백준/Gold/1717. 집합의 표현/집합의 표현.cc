#include <iostream>

using namespace std;

int nums[1'000'001];

int func_getParent(int num){
    if(nums[num] == num) return num;
    return nums[num] = func_getParent(nums[num]);
}

void func_union(int b, int c){
    b = func_getParent(b);
    c = func_getParent(c);
    if(b < c) nums[c] = b;
    else nums[b] = c;
}

void func_find(int b, int c){
    b = func_getParent(b);
    c = func_getParent(c);
    if(b == c) cout << "YES\n";
    else cout << "NO\n";
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n, m;
    cin >> n >> m;

    for(int i=0; i<=n; i++) nums[i] = i;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        if(a==0) func_union(b, c);
        else if(a==1) func_find(b, c); 
    }

    return 0;
}
#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void func(int k){
    if (k==m){
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++){
        if(!visited[i]){
            arr[k] = i;
            visited[i] = 1;
            func(k+1);
            visited[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> n >> m;
    func(0);
}
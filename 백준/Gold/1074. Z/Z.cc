#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, answer;
bool chk;

void zFunc(int x, int y, int w){
    if(chk) return;

    if(pow(2,w-1) != 1){
        for(int i=x; i<x+pow(2,w); i+=pow(2,w-1)){
            for(int j=y; j<y+pow(2,w); j+=pow(2,w-1)){
                if(i<=r && r<i+pow(2,w-1) && j<=c && c<j+pow(2,w-1)){
                    zFunc(i, j, w-1);
                }else if(!chk){
                    answer += (pow(2,w-1)*pow(2,w-1));
                }
            }
        }
    }
    else if(pow(2,w-1) == 1){
        int dx[4] = {0, 0, 1, 1};
        int dy[4] = {0, 1, 0, 1};

        for(int i=0; i<4; i++){
            if(x+dx[i]==r && y+dy[i]==c) {
                chk = true;
                break;
            }
            answer++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    cin >> n >> r >> c;

    zFunc(0, 0, n);

    cout << answer;
    return 0;
}
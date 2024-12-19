#include <iostream>

char lc[27];
char rc[27];

using namespace std;

void preorder(int n)
{
    cout << char(n+65);
    if(lc[n] != '.') preorder(lc[n]-65);
    if(rc[n] != '.') preorder(rc[n]-65);
}

void inorder(int n)
{
    if(lc[n] != '.') inorder(lc[n]-65);
    cout << char(n+65);
    if(rc[n] != '.') inorder(rc[n]-65);
}

void postorder(int n)
{
    if(lc[n] != '.') postorder(lc[n]-65);
    if(rc[n] != '.') postorder(rc[n]-65);
    cout << char(n+65);
}

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int n;
    cin >> n;


    while(n--)
    {
        char P, L, R;
        cin >> P >> L >> R;
        int index = (P-65);
        lc[index] = L;
        rc[index] = R;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}
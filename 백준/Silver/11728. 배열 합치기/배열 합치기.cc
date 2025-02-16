#include <iostream>

using namespace std;

int A[1'000'002];
int B[1'000'002];

int main(void){
    ios::sync_with_stdio(0); // c stream, c++ stream 중 c++ stream만 사용
    cin.tie(0); // 버퍼 비우지 않음

    int a, b;
    cin >> a >> b;

    for(int i=0; i<a; i++) cin >> A[i];
    for(int i=0; i<b; i++) cin >> B[i];

    int* a_pointer = A;
    int* b_pointer = B;

    while(true)
    {
        if(a_pointer == (A+a) && b_pointer == (B+b)) break;

        if(a_pointer == (A+a))
        {
            cout << *b_pointer++ << " ";
            continue;
        }

        if(b_pointer == (B+b))
        {
            cout << *a_pointer++ << " ";
            continue;
        }

        if(*a_pointer > *b_pointer) cout << *b_pointer++ << " ";
        else cout << *a_pointer++ << " ";
    }
    
    return 0;
}
// 방학숙제
#include <iostream>
#include <algorithm>
using namespace std;
int L, A, B, C, D;
 
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> L >> A >> B >> C >> D;
 
    int temp1 = L - (A / C);
    if(A%C){ temp1--; }

    int temp2 = L - (B / D);
    if(B%D){ temp2--; }

    cout << min(temp1, temp2) << "\n";
    return 0;
}
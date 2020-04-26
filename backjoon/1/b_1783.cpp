// 병든 나이트
#include <iostream>
using namespace std;
int N, M, result;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    if(N == 1){ result = 1; }
    else if(N == 2){ result = min(4, (M+1)/2 ); }
    else{
        if(M <= 6){ result = min(4, M); }
        else{ result = M-2; }
    }

    cout << result;
}
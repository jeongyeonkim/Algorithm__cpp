// 동전
#include <iostream>
#include <string.h>
using namespace std;
int T, N, M;
int coin[6], result[21];

int cntCoin(){
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        memset(coin, 0, sizeof(coin));
        for(int j=0; j<N; i++){ cin >> coin[i]; }
        cin >> M;
        result[i] = cntCoin();
    }

    for(int i=0; i<T; i++){
        cout << result[i] << "\n";
    }
}
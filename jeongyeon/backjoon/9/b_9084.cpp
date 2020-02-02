// 동전
#include <iostream>
#include <string.h>
using namespace std;
int T, N, M;
int coin[20], result[10001];

int cntCoin(){
    result[0]=1;

    for(int i=0; i<=N; i++){
        for(int j=coin[i]; j<=M; j++){
            result[j] += result[j-coin[i]];
        }
    }

    return result[M];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        memset(coin, 0, sizeof(coin));
        for(int j=0; j<N; j++){ cin >> coin[i]; }
        cin >> M;

        cout << cntCoin() << "\n";
    }
}
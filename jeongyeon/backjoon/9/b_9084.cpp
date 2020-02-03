// 동전
#include <iostream>
#include <cstring>
using namespace std;
int T, N, M;
int coin[20], result[10001], output[10];

int cntCoin(){
    memset(result, 0, sizeof(result));
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
        for(int j=0; j<N; j++){ cin >> coin[j]; }
        cin >> M;
        output[i] = cntCoin();
    }

    for(int i=0; i<T; i++){
        cout << output[i] << "\n";
    }
}
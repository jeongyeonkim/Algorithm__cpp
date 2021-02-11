// // 동전
#include <iostream>
#include <string.h>
using namespace std;
int N, M, T;
int coin[20], result[10001];
 
int maxCoin(void){
        memset(result, 0, sizeof(result));
        result[0] = 1;
        for(int i=0; i<N; i++){
            for (int j=coin[i]; j<=M; j++){
               result[j] += result[j - coin[i]];
           }
        }
        return result[M];
}
 
int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        memset(coin, 0, sizeof(coin));
        for(int i=0; i<N; i++){ cin >> coin[i]; }
        cin >> M;
        cout << maxCoin() << "\n";
    }
}
// 합분해
#include <iostream>
#define divi 1000000000
using namespace std;
int N, K;
long long decompose[201][201];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        decompose[i][1] = 1;
    }
    for(int i=1; i<=K; i++){
        decompose[1][i] = i;
    }

    for(int i=2; i<=N; i++){
        for(int j=2; j<=K; j++){
            decompose[i][j] = (decompose[i-1][j] + decompose[i][j-1])%divi;
        }
    }
    cout << decompose[N][K];
}
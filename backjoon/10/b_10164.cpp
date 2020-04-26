// 격자상의 경로
#include <iostream>
using namespace std;
int N, M, K, X, Y, result = 1;
long long dp[16][16];

void Route(int s, int e, int x, int y){
    dp[s][e-1] = 1;
    dp[s-1][e] = 0;
    for(int i=s; i<=x; i++){
        for(int j=e; j<=y; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    result *= dp[x][y];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    if(K != 0){
        if(K%M != 0){ 
            X = K/M+1;
            Y = K%M;
        }
        else{
            X = K/M;
            Y = M;
        }
        Route(1, 1, X, Y);
        Route(X, Y, N, M);
    }else{
        Route(1, 1, N, M);
    }

    cout << result;
}
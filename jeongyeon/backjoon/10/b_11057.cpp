//오르막수
#include <iostream>
using namespace std;
int N, sum;
int dp[1001][10];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k];
            }
            dp[i][j] %= 10007;
        }
    }

    for(int i=0; i<=9; i++){
        sum += dp[N][i];
    }
    cout << sum%10007;
}
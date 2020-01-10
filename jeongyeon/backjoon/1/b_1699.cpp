//제곱수의 합
//루트 씌운 값부터 N값에서 빼가면서 Dynamic programming
#include <iostream>
using namespace std;
int N, dp[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=1; i<=N; i++){
        dp[i] = i;
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i-j*j] + 1, dp[i]);
        }
    }

    cout << dp[N];
}
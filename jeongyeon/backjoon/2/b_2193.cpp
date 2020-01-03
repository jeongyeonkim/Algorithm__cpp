//이친수
#include <iostream>
using namespace std;
int N;
long long dp[91];

long long num(){
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    cout << num();
}
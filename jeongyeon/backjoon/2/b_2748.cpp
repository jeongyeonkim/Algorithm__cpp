#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n=0;
    cin >> n;
    long long dp[n];
    dp[0] = 0; dp[1]=1;
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1]+dp[i-2];
    
    cout << dp[n];
    return 0;
}
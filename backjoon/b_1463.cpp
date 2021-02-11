#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    int dp[n+1];
     
    dp[1]=0; 
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] +1;
        if(i%3 == 0)
            dp[i] = min(dp[i/3] +1, dp[i]);
        else if(i%2 == 0)
            dp[i] = min(dp[i/2] +1, dp[i]);
    }
    cout << dp[n];
    return 0;
}
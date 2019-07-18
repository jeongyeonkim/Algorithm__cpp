#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t=0;
    cin >> t;
    int arr[t];
    long long dp[101];
    for(int i=1; i<=t; i++)
        cin >> arr[i];
        
    dp[0]=1; dp[1]=1; dp[2]=1;
    dp[3]=2; dp[4]=2;
    dp[5]=3;
    for(int i=6; i<=100; i++)
        dp[i] = dp[i-1] + dp[i-5];
    
    for(int i=1; i<=t; i++)
        cout << dp[arr[i]-1] << "\n";
    return 0;
}
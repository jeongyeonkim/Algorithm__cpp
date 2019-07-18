#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t=0;
    cin >> t;
    int arr[t];
    int dp[41][2];
    for(int i=0; i<t; i++)
        cin >> arr[i];
    dp[0][0]=1; dp[0][1]=0;
    dp[1][0]=0; dp[1][1]=1;
    for(int i=2; i<=40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1]; 
    }
    for(int i=0; i<t; i++)
        cout << dp[arr[i]][0] << " " << dp[arr[i]][1] << "\n";
    return 0;
}
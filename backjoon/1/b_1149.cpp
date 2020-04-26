#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, MIN=0;
    cin >> n;
    int dp[n][3];
    int arr[n][3];
    
    for(int i=0; i<n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1]+arr[i][0], dp[i-1][2]+arr[i][0]);
        dp[i][1] = min(dp[i-1][0]+arr[i][1], dp[i-1][2]+arr[i][1]);
        dp[i][2] = min(dp[i-1][0]+arr[i][2], dp[i-1][1]+arr[i][2]);
    }
    if(dp[n-1][0] < dp[n-1][1])
        MIN = min(dp[n-1][0], dp[n-1][2]);
    else
        MIN = min(dp[n-1][1], dp[n-1][2]);
        
    cout << MIN;
    return 0;    
}
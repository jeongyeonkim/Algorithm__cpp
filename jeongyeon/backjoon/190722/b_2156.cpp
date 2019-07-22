#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    int arr[n]={0,}, dp[n]={0,};
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    dp[0]=arr[0]; dp[1]=arr[0]+arr[1];
    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-3]+arr[i-1]+arr[i], max(dp[i-2]+arr[i] ,dp[i-1]));
    }
    cout << dp[n-1];
    return 0;
}
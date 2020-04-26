// 가장 긴 증가하는 수열
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, MAX=0;
    cin >> n;
    int arr[n], dp[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    for(int i=0; i<n; i++)
        MAX=max(MAX, dp[i]);
    
    cout << MAX;
    return 0;
}
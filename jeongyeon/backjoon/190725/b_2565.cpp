#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int n=0, MAX=0; cin >> n;
    pair<int, int> arr[n];
    int dp[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
        dp[i] =1;
    }
    sort(arr, arr+n);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i].first > arr[j].second && arr[j].first <= arr[i].second)
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    for(int i=0; i<n; i++)
        MAX = max(MAX, dp[i]);
    cout << n-MAX;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500];
int dp[500][500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n=0, output=0;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cin >> arr[i][j];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
    }

    for(int i=0; i<n; i++)
        output = max(output, dp[n-1][i]);
    
    cout << output;
    return 0;
}
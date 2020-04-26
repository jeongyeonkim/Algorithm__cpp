//스티커
#include <iostream>
#include <algorithm>
using namespace std;
int T, n, arr[2][100001], dp[2][100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    int result[T+1];
    for(int i=0; i<T; i++){
        cin >> n;
        for(int j=1; j<=n; j++){
            cin >> arr[0][j];
        }
        for(int j=1; j<=n; j++){
            cin >> arr[1][j];
        }

        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];

        for(int k=2; k<=n; k++){
            dp[0][k] = max(dp[1][k-2] + arr[0][k], dp[1][k-1] + arr[0][k]);
            dp[1][k] = max(dp[0][k-2] + arr[1][k], dp[0][k-1] + arr[1][k]);
        }
        result[i] = max(dp[0][n], dp[1][n]);
    }

    for(int i=0; i<T; i++){
        cout << result[i] << "\n";
    }
}
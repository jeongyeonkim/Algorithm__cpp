#include <iostream>
#include <algorithm>
using namespace std;
int W[101];
int V[101];
int dp[101][100001];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N=0, K=0;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i] <= j) {
                int free_w = j - W[i];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][free_w] + V[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
}

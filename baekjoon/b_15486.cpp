// 퇴사2
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int T[1500001], P[1500001], dp[1500001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> T[i] >> P[i]; }

    for (int i = N - 1; i >= 0; i--) {
        if (i + T[i] >= N + 1) {
            dp[i] = max(dp[i + 1], 0);
            continue;
        }

        dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
    }
    cout << dp[0];
    return 0;
}
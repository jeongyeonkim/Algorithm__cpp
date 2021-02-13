//퇴사
#include <iostream>
#include <algorithm>
using namespace std;
int N, arrT[15], arrP[16], dp[16];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arrT[i] >> arrP[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i + arrT[i] >= N + 1) {
            dp[i] = max(dp[i + 1], 0);
            continue;
        }

        dp[i] = max(dp[i + arrT[i]] + arrP[i], dp[i + 1]);
    }

    cout << dp[0];
}
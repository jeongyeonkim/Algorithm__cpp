//다리 놓기 
//조합으로 풀기 mCn
#include <iostream>
#include <cstring>
using namespace std;
int T;
int dp[31][31];

int combination(int n, int r){
    if(n == r || r == 0) { return 1; }
    if(dp[n][r]) { return dp[n][r]; }
    return dp[n][r] = combination(n - 1, r - 1) +combination(n - 1, r);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    int result[T+1];
    for(int i=0; i<T; i++){
        memset(dp, 0, sizeof(dp));
        int N, M;
        cin >> N >> M;
        result[i] = combination(M, N);
    }

    for(int i=0; i<T; i++){
        cout << result[i] << "\n";
    }
}
// 극장 좌석
#include <iostream>
using namespace std;
int N, M, result = 1, cnt;
int arr[41];
long long dp[41];

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int temp;
        cin >> temp;
        arr[i] = (temp - cnt - 1);
        cnt = temp;
    }
    arr[M] = N-cnt;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    for(int i=0; i<=M; i++){
        result *= dp[arr[i]];
    }

    cout << result;
}

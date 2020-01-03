//카드 구매하기
#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1001];
long long dp[1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i-j]+arr[j], dp[i]);
        }
    }
    cout << dp[N];

}
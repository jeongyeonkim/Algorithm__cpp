// 자와 각도기
#include <iostream>
using namespace std;
int N, K;
int arrN[11], num[361], dp[11][361];

void sol(int idx, int sum){
    num[sum] = 1;
    if(idx == N){ return; }
    if(dp[idx][sum] == 1){ return; }
    dp[idx][sum] = 1;
    sol(idx + 1, (sum + arrN[idx]) % 360);
    sol(idx, (sum + arrN[idx]) % 360);
    sol(idx + 1, (sum - arrN[idx] + 360) % 360);
}

int main(void){
    ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++){ cin >> arrN[i]; }
    sol(0, 0);

    for(int i=0; i<K; i++){
        int input; cin >> input;
        if(num[input] == 1){ cout << "YES\n"; }
        else{ cout << "NO\n"; }
    }
    return 0;
}
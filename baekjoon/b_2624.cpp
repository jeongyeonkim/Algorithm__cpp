// 동전 바꿔주기
#include <iostream>
#include <vector>
using namespace std;
int T, k;
int dp[10001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T >> k;
    int input1, input2;
    dp[0] = 1;
    while (k--){
        cin >> input1 >> input2;

        for(int i=T; i>=0; i--){
            for(int j=1; j<=input2; j++){
                if(i - input1*j >= 0){ dp[i] += dp[i - input1*j]; }
            }
        }
    }
    cout << dp[T];

    return 0;
}
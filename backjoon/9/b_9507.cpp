//Generations of Tribbles
#include <iostream>
using namespace std;
int t;
long long dp[68]={1, 1, 2, 4, };

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    for(int i=4; i<68; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }

    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }
}
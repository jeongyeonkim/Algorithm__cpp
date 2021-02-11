// 1,2,3 더하기
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int n; scanf("%d", &n);
        int dp[n+1];
        dp[0]=0; dp[1]=1; dp[2]=2; dp[3]=4;
        
        for(int j=4; j<=n; j++)
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        
        printf("%d\n", dp[n]);
    }
    return 0;
}
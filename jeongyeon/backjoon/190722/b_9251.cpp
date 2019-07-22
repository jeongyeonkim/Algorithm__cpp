#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    string input1, input2;
    cin >> input1;  cin >> input2;

    for(int i=1; i<=input1.length(); i++){
        for(int j=1; j<=input2.length(); j++){
            if(input1[i-1] == input2[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    cout << dp[input1.length()][input2.length()];
    return 0;
}
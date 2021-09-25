// 호텔 방 번호
// 
#include <iostream>
#include <string.h>
using namespace std;
int N, M;
int dp[5001];
bool checkNumber[11];

void resetCheckNumer(){
    for(int i=0; i<=10; i++){ checkNumber[i] = false; }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[1] = 1;

    for(int i=2; i<=5000; i++){
        bool passNumber = true;
        string str = to_string(i);
        resetCheckNumer();
        int k = str.length() - 1;

        while(k >= 0){
            if(checkNumber[str[k] - '0']){
                passNumber = false;
                break;
            }
            checkNumber[str[k] - '0'] = true;

            k--;
        }
        
        dp[i] = dp[i-1] + (int)passNumber;
    }

    while (cin >> N >> M) {
        cout << dp[M] - dp[N-1] << "\n";
    }
}
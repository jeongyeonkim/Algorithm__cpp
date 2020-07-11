// 개근상
#include <iostream>
#include <string.h>
#define K 1000000
using namespace std;
int N;
long long dp[1001][3][2];

long long attend(int day, int absense, int perception){
    if(absense == 3 || perception == 2){ return 0; }
    if(day == N){ return 1; }
    if(dp[day][absense][perception] != -1){ return dp[day][absense][perception]; }

    dp[day][absense][perception] = attend(day + 1, 0, perception) + attend(day + 1, 0, perception + 1) + attend(day + 1, absense + 1, perception);
    dp[day][absense][perception] %= K;
    return dp[day][absense][perception];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << attend(0, 0, 0) % K;
    return 0;
}
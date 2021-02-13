// 외판원 순회
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, result;
int arr[17][17];
int dp[17][1<<16];

int tsp(int now, int visited){ // 현재 몇번 째 마을에 위치하는지, 어느 마을을 방문하고 왔는지
    int res = dp[now][visited];
    if(res != 0){ return res; } // 이미 구한적 있다면

    if(visited == (1<<N) - 1){
        if(arr[now][0] != 0){ return arr[now][0]; }
        return 1e9;
    }

    res = 1e9;
    for(int i=0; i<N; i++){
        if((visited & 1<<i) || (arr[now][i] == 0)){ continue; } // i번째 visited를 확인하기 위한 bit 연산
        result = tsp(i, (visited | 1<<i)) + arr[now][i];
        if(result < res){ res = result; }
    }
    dp[now][visited] = res;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ cin >> arr[i][j]; }
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1);
}
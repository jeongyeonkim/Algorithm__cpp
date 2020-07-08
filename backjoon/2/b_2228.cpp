// 구간 나누기 
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[101], visited[101][101], dp[101][101];

int divide(int idx, int num){
    if(num == 0){ return 0; }
    if(idx < (num*2) - 1){ return -1e9; }
    if(visited[idx][num] == 1) { return dp[idx][num]; }

    visited[idx][num] = 1;
    dp[idx][num] = divide(idx - 1, num);

    for(int i=idx; i>0; i--){
        dp[idx][num] = max(dp[idx][num], arr[idx] - arr[i - 1] + divide(i-2, num - 1));
    }
    return dp[idx][num];
}

int main(void){
    ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int temp = 0;
    
    for(int i=1; i<=N; i++){
        cin >> temp;
        arr[i] = arr[i-1] + temp;
    }

    cout << divide(N, M);
    return 0;
}
// 주유소
#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long arr[100001], price[100001], dp[100001];
long long result, temp;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N-1; i++){ cin >> arr[i]; }
    for(int i=0; i<N; i++){ cin >> price[i]; }

    dp[0] = arr[0] * price[0];
    temp = price[0];
    for(int i=1; i<N; i++){
        if(temp > price[i]){ // 현재까지 방문한 주유소 중에 가격이 가장 작은 주유소에서 기름 채우는 것이 이득
            temp = price[i];
        }
        dp[i] = dp[i-1] + temp * arr[i];
    }

    cout << dp[N-1];
    return 0;
}
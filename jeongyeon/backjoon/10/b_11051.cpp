// 이항 계수2
#include <iostream>
#define div 10007;
using namespace std;
int N, K;
int arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        arr[i][1] = i;
        arr[i][0] = arr[i][i] = 1;
    }
    for(int i=3; i<=N; i++){
        for(int j=2; j<=i; j++){
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%div;
        }
    }

    cout << arr[N][K]%div;
}
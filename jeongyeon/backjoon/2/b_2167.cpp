//2차원 배열의 합
//열 기준으로 Dynamic programming
#include <iostream>
#include <vector>
using namespace std;
int N, M, K, dp[301][301];
vector<int> result;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){ 
            int input;
            cin >> input;
            dp[i][j] = dp[i-1][j] + input;
        }
    }
    cin >> K;

    while(K--){
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        int sum = 0;
        for(int a=j; a<=y; a++){
            sum += (dp[x][a] - dp[i-1][a]);
        }
        result.push_back(sum);
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}
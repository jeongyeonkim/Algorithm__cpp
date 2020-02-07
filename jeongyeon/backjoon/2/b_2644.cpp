// 촌수 계산
// BFS 풀이
#include <iostream>
#include <queue>
using namespace std;
int arr[101][101], dp[101];
queue<int> que;
int n, m, x, y;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y >> m;
    for(int i=0; i<m; i++){
        int a = 0, b = 0;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    que.push(x);
    while(!que.empty()){
        int k = que.front();
        que.pop();
        
        for(int i=1; i<=n; i++){
            if(arr[k][i] == 0 || dp[i] != 0){ continue; }
            dp[i] = dp[k] + 1;
            que.push(i);
        }
    }
    
    if(dp[y] == 0){ cout << -1; }
    else{ cout << dp[y]; }

    return 0;
}
// 이동하기
#include <iostream>
using namespace std;
int N, M;
int maze[1001][1001], candy[1001][1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){ cin >> maze[i][j];};
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            candy[i][j] = maze[i][j] + max(candy[i-1][j-1], max(candy[i-1][j], candy[i][j-1]));
        }
    }

    cout << candy[N][M];
}  
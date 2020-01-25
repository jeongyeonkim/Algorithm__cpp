// 점프
#include <iostream>
#include <string.h>
using namespace std;
int N, arr[101][101];
long long gameMap[101][101];

long long jump(int x, int y){
    if(gameMap[x][y] != -1){ return gameMap[x][y]; }
    if(x > N && y > N){ return 0; }
    if(x == N && y == N){ return 1; }

    gameMap[x][y] = 0;

    gameMap[x][y] += jump(x+arr[x][y], y);
    gameMap[x][y] += jump(x, y+arr[x][y]);

    return gameMap[x][y];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){ cin >> arr[i][j]; }
    }
    memset(gameMap, -1, sizeof(gameMap));
    cout << jump(1,1);
}
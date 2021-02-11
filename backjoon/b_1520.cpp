// 내리막 길
#include <iostream>
#include <string.h>
using namespace std;
int N, M, arr[501][501], Map[501][501];
int k[4] = {1, 0, -1, 0};
int l[4] = {0, 1, 0, -1};

int downward(int x, int y){
    if(Map[x][y] != -1){ return Map[x][y]; }
    if(x<=0 || x>N || y<=0 || y>M){ return 0; }
    if(x==1 && y==1){ return 1; }

    Map[x][y] = 0;
    for(int i=0; i<4; i++){
        int tempX = x+k[i];
        int tempY = y+l[i];

        if(arr[x][y] < arr[tempX][tempY]){
            Map[x][y] += downward(tempX, tempY);
        }
    }

    return Map[x][y];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){ cin >> arr[i][j]; }
    }
    memset(Map, -1, sizeof(Map));

    cout << downward(N, M);
}
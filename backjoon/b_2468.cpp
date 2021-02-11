// 안전 영역
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, safety, maxHight, minHight=100, result = 1, cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[101][101], visited[101][101];

void safetyArea(int m, int x, int y){
    visited[x][y] = 1;
    int nx, ny;

    for(int i=0; i<4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >=0 && nx < N && ny >= 0 && ny <N){
            if(visited[nx][ny] == 0 && arr[nx][ny] > m){
                safetyArea(m, nx, ny);
            }
        }
    }
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            maxHight = max(maxHight, arr[i][j]);
            minHight = min(minHight, arr[i][j]);
        }
    }

    for(int i=minHight; i<maxHight; i++){
        cnt = 0;
        memset(visited, 0, sizeof(visited));

        for(int j=0; j<N; j++){
            for(int z=0; z<N; z++){
                if(visited[j][z] == 0 && arr[j][z] > i){
                    safetyArea(i, j, z);
                    cnt++;
                }
            }
        }

        result = max(result, cnt);
    }
    cout << result;
}
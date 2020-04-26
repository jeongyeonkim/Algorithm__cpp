// 적록 색약
#include <iostream>
#include <string.h>
using namespace std;
int N, result1, result2;
int arr[101][101], visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void blindness(int x, int y, int k){
    visited[x][y] = 1;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
            if(visited[nx][ny] == 0 && arr[nx][ny] == k){
                blindness(nx, ny, k);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char a; cin >> a;
            if(a == 'R'){ arr[i][j] = -1; }
            else if(a == 'B'){ arr[i][j] = 1; }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                blindness(i, j, arr[i][j]);
                result1++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == -1){ arr[i][j] = 0; }
        }
    }

    memset(visited, 0, sizeof(visited));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                blindness(i, j, arr[i][j]);
                result2++;
            }
        }
    }

    cout << result1  << " " << result2;
}
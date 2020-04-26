// 섬의 개수
#include <iostream>
#include <string.h>
using namespace std;
int w, h, result;
int arr[51][51], visited[51][51];
int dx[8] = {-1, -1, 1, 1, 1, -1, 0, 0};
int dy[8] = {-1, 1, -1, 1, 0, 0, 1, -1};

// 방문하지 않았거나 대각선, 가로, 세로로 갈 수 있을 경우 재귀
void island(int x, int y){
    visited[x][y] = 1;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= h || ny >=w){ continue; }
        if(visited[nx][ny] == 0 && arr[nx][ny] == 1){ island(nx, ny); }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true){
        cin >> w >> h;
        // 0 0 입력되면 프로세스 종료
        if(h == 0 && w == 0){ break; }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){ cin >> arr[i][j]; }
        }
    
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visited[i][j] == 0 && arr[i][j] == 1){
                    result++;
                    island(i, j);
                }
            }
        }

        cout << result << "\n";
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        result = 0;
    }
    
    return 0;
}
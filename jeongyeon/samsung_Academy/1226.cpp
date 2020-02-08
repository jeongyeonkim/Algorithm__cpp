//[S/W 문제해결 기본] 7일차 - 미로1
#include <iostream>
#include <string.h>
using namespace std;
int test_case, T, result, startX, startY;
int maze[16][16], visited[16][16];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void findExit(int x, int y){
    visited[x][y] = 1;

    if(maze[x][y] == 3){
        result = 1;
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= 16 || ny < 0 || ny >= 16){ continue; }
        if(visited[nx][ny] == 0 && (maze[nx][ny] == 0 || maze[nx][ny] == 3)){
            findExit(nx, ny);
        }
    }
}

int main(int argc, char** argv){
    for(test_case = 1; test_case <= 1; ++test_case){
        cin >> T;
        memset(maze, 0 ,sizeof(maze));
        memset(visited, 0 ,sizeof(visited));
        startX = startY = 0;
        result = 0;
        
        for(int i=0; i<16; i++){
            for(int j=0; j<16 ; j++){
                scanf("%1d", &maze[i][j]);
                if(maze[i][j] == 2){
                    startX = i;
                    startY = j;
                }
            }
        }

        findExit(startX, startY);
        cout << "#" << T << " " << result << "\n";
    }

    return 0;
}
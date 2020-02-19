// 탈출
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int R, C, startX, startY, endX, endY;
// 0 = 빈 곳, 1 = 물차있는 곳, -1 = 돌, 2 = 비버의 굴
int arr[51][51], visited[51][51], waterVisited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char a;
queue<pair <int, int> > hedgehog;
queue<pair <int, int> >  waterArea;

void exodus(){
    // 물 차는 곳 표시
    while (!waterArea.empty()){
        int x = waterArea.front().first;
        int y = waterArea.front().second;
        waterArea.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C){ continue; }
            if(arr[nx][ny] == 0 && waterVisited[nx][ny] == 0){
                // 해당 좌표가 물에 차게되는 시간 저장
                waterVisited[nx][ny] = waterVisited[x][y] + 1;
                waterArea.push(make_pair(nx, ny));
            }
        }
    }

    while (!hedgehog.empty()){
        int x = hedgehog.front().first;
        int y = hedgehog.front().second;
        hedgehog.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C){ continue; }
            if(visited[nx][ny] == 0 && (arr[nx][ny] == 0 || arr[nx][ny] == 2)){
                // 물에 아예 차지 않았거나, 물이 차기전 방문할 경우 큐에 저장.
                if((waterVisited[nx][ny] > visited[x][y] + 1) || waterVisited[nx][ny] == 0){
                    visited[nx][ny] = visited[x][y] + 1;
                    hedgehog.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(void){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%1s", &a);
            if(a == '*'){
                arr[i][j] = 1;
                // 모든 물 시작 점 queue에 저장
                waterArea.push(make_pair(i, j));
            }
            if(a == 'X'){ arr[i][j] = -1; }
            if(a == 'D'){
                arr[i][j] = 2;
                endX = i; endY = j;
            }
            if(a == 'S'){
                startX = i; startY = j;
                hedgehog.push(make_pair(startX, startY));
            }
        }
    }

    exodus();

    // 아예 방문할 수 없을 경우 KAKTUS 출력
    if(visited[endX][endY] == 0){ cout << "KAKTUS"; }
    else{ cout << visited[endX][endY]; }
}
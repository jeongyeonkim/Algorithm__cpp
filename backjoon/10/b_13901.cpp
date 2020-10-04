// 로봇
// 1. 시뮬레이션
// 2. 방향을 총 4번 바꾸었을 때 종료 시킴.
// 3. _map에 미방문 = 0, 방문 = 1, 장애물 = -1 >>> visit배열 따로 안 만들음.
#include <iostream>
using namespace std;
int R, C, k, br, bc, d;
pair<int, int> startL, endL;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int _map[1001][1001], dir[4];

int changeDir(int n){
    if(n == 1){ return 3; }
    if(n == 2){ return 1; }
    if(n == 3){ return 2; }
    return 0;
}

void runLobot(int di){
    for(int i=0; i<4; i++){
        int nx = endL.first + dx[dir[(di + i) % 4]];
        int ny = endL.second + dy[dir[(di + i) % 4]];
        if(nx < 0 || ny < 0 || nx >= R || ny >= C || _map[nx][ny] != 0){ continue; }
        endL.first = nx; endL.second = ny;
        di = (di + i) % 4;
        _map[nx][ny] = 1;
        runLobot(di);
        return;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> k;
    for(int i=0; i<k; i++){
        cin >> br >> bc;
        _map[br][bc] = -1;
    }
    cin >> startL.first >> startL.second;
    _map[startL.first][startL.second] = 1;
    for(int i=0; i<4; i++){
        cin >> d;
        dir[i] = changeDir(d);
    }

    endL.first = startL.first;
    endL.second = startL.second;
    runLobot(0);

    cout << endL.first << " " << endL.second;
    return 0;
}
// [S/W 문제해결 기본] 2일차 - Ladder1
#include <iostream>
#include <string.h>
using namespace std;
int test_case, T, result, finish;
int ladder[100][100];
int dx[3] = {-1, 0, 0};
int dy[3] = {0, -1, 1};

bool checkStation(int x, int y, int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || ny < 0 || nx >= 100 || ny >= 100){ return false; }
    if(ladder[nx][ny] == 1 ){ return true; }
    return false;
}

void findStart(int x, int y, int dir){
    if(x == 0){
        result = y;
        return;
    }

    // 위로 가는 방향을때 가로 존재하는지 체크
    if(dir == 0){
        if(checkStation(x, y, 1)){ findStart(x + dx[1], y + dy[1], 1); }
        else if(checkStation(x, y, 2)){ findStart(x + dx[2], y + dy[2], 2); }
        else{ findStart(x + dx[0], y + dy[0], 0); }
    }// 가로로 가는 방향일때 위에 존재하는지 체크
    else{
        if(checkStation(x, y, 0)){ findStart(x + dx[0], y + dy[0], 0); }
        else{ findStart(x + dx[dir], y + dy[dir], dir); }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(test_case = 1; test_case <= 10; ++test_case){
        cin >> T;
        memset(ladder, 0, sizeof(ladder));
        result = 0;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> ladder[i][j];
                if(i == 99 && ladder[i][j] == 2){ finish = j; }
            }
        }
        // 맨 밑에서 위로 올라감.
        findStart(99, finish, 0);
        cout << "#" << T << " " << result << "\n";
    }

    return 0;
}

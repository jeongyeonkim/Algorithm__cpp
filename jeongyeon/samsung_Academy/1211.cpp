// [S/W 문제해결 기본] 2일차 - Ladder2
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int test_case, T;
int result, temp= 10000, countSize;
int arr[101][101];
vector<int> startPoint;
// 아래, 오른쪽, 왼쪽
int dx[3] = {1, 0, 0};
int dy[3] = {0, 1, -1};

bool checkStation(int x, int y, int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || ny < 0 || nx >= 100 || ny >= 100){ return false; }
    if(arr[nx][ny] == 1 ){ return true; }
    return false;
}

void Ladder(int x, int y, int dir, int cnt){
    if(x == 99){ countSize = cnt; return; }

    // 아래로 가는 방향일 때 양 옆으로 갈 수 있는지 체크
    if(dir == 0){
        if(checkStation(x, y, 1)){ Ladder(x + dx[1], y + dy[1], 1, cnt + 1); }
        else if(checkStation(x, y, 2)){ Ladder(x + dx[2], y + dy[2], 2, cnt + 1); }
        else{ Ladder(x + dx[0], y + dy[0], 0, cnt + 1); }
    }
    // 옆으로 가는 방향일 때 아래로 갈 수 있는지 체크 
    else{
        if(checkStation(x, y, 0)){ Ladder(x + dx[0], y + dy[0], 0, cnt + 1); }
        else{ Ladder(x + dx[dir], y + dy[dir], dir, cnt + 1); }
    }
}

int main(int argc, char** argv){
    for(test_case = 1; test_case <= 10; ++test_case){
        cin >> T;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> arr[i][j];
                if(i == 0 && arr[i][j] == 1){ startPoint.push_back(j); }
            }
        }

        for(int i=0; i<startPoint.size(); i++){
            Ladder(0, startPoint[i], 0, 1);
            if(countSize <= temp){
                temp = countSize;
                result = startPoint[i];
            }
        }

        cout << "#" << T << " " << result << "\n"; 
        startPoint.clear();
        memset(arr, 0, sizeof(arr));
        temp = 10000;
    }

    return 0;
}
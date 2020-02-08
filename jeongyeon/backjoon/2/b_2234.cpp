// 성곽
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector<int> result;
vector<pair<int,int> > roomNum;
int n, m, cnt, maxArea;
// 남, 동, 북, 서
int arr[51][51][4], visited[51][51], arrNum[51][51][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool checkWell(int x, int y){
    for(int i=0; i<4; i++){
        if(arr[x][y][i] == 0){ return true; }
    }
    return false;
}

void DFS(int x, int y){
    visited[x][y] = 1;
    cnt++;

    if(checkWell(x, y)){
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
            if(arr[x][y][i] == 0 && visited[nx][ny] == 0){
                DFS(nx, ny);
                roomNum.push_back(make_pair(nx, ny));
            }
        }
    }
}

void binary(int x, int y, int k){
    int j = 8;
    for(int i=0; i<4; i++){
        arr[x][y][i] = k/j;
        k = k%j;
        j /= 2;
    }
}

void breakWall(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
        // 벽이 있으면서 방번호 다른 곳 벽 부시기
        // 양쪽 방 크기 합쳐서 최대 넓이 갱신
        if(arr[x][y][i] == 1 && arrNum[x][y][0] != arrNum[nx][ny][0]){
            maxArea = max(maxArea, arrNum[nx][ny][1] + arrNum[x][y][1]);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a=0; cin >> a;
            binary(i, j, a);
        }
    }

    // 1, 2번 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == 0){
                DFS(i, j);
                result.push_back(cnt);
                // 방 번호 붙임 arrNum[x][y][0] = 방번호, arrNum[x][y][1] = 방크기
                arrNum[i][j][1] = cnt;
                arrNum[i][j][0] = result.size();
                for(int z=0; z<roomNum.size(); z++){
                    arrNum[roomNum[z].first][roomNum[z].second][0] = result.size();
                    arrNum[roomNum[z].first][roomNum[z].second][1] = cnt;
                }
                cnt = 0;
                roomNum.clear();
            }
        }
    }
    
    // 3번 벽 부시기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            breakWall(i, j);
        }
    }

    cout << result.size() << "\n";
    int maxSize = 0;
    for(int i=0; i<result.size(); i++){
        maxSize = max(maxSize, result[i]);
    }
    cout << maxSize << "\n";
    cout << maxArea;
}
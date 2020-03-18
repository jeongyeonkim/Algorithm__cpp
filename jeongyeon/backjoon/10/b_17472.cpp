// 다리 만들기2
// 완전탐색
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int N, M, result = 987654321, areaNum = 1;
int arr[11][11], Area[11][11];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> area[100];

void graph(int num, int cnt, int sum){
    if(cnt == areaNum){ result = min(result, sum); return; }

    for(int i=1; i<=areaNum; i++){

    }

}

bool range(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >=M){ return false; }
    return true;
}

void move(int x, int y, int num){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int cnt = 0;

        while(true){
            if(range(nx, ny) == true){
                if(arr[nx][ny] == 0){
                    cnt++;
                    nx += dx[i]; ny += dy[i];
                }else if(arr[nx][ny] != num && cnt >= 2){
                    if(!Area[num][arr[nx][ny]] || !Area[arr[nx][ny]][num]){
                        area[num].push_back(arr[nx][ny]);
                        area[arr[nx][ny]].push_back(num);
                    }
                    if(!Area[num][arr[nx][ny]] || Area[num][arr[nx][ny]] > cnt){
                        Area[num][arr[nx][ny]] = cnt;
                    }
                    if(!Area[arr[nx][ny]][num] || Area[arr[nx][ny]][num] > cnt){
                        Area[arr[nx][ny]][num] = cnt;
                    }
                    break;
                }else{ break; }
            }else{ break; }
        }
    }
}

void numberArea(int x, int y){
    visited[x][y] = true;
    arr[x][y] = areaNum;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
        if(!visited[nx][ny] && arr[nx][ny] == 1){ numberArea(nx, ny); }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && arr[i][j] == 1){
                numberArea(i, j);
                areaNum++;
            }
        }
    }
    areaNum--;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] != 0){ move(i, j, arr[i][j]); }
        }
    }

    for(int i=1; i<=areaNum; i++){
        for(int j=1; j<=areaNum; j++){ cout << Area[i][j] << " "; }
        cout << "\n";
    }
    
    graph(1, 1, 0);

    if(result == 987654321){ result = -1; }
    cout << result;
}
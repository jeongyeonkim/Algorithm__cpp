// 보물섬
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, result;
char arr[51][51];
int visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int Treasure(int x, int y){
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > que;
    que.push(make_pair(x, y));
    visited[x][y] = 1;

    while (!que.empty()){
        int px = que.front().first;
        int py = que.front().second;
        que.pop();
        cnt = max(cnt, visited[px][py]);

        for(int i=0; i<4; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M){ continue; }
            if(visited[nx][ny] == 0 && arr[nx][ny] == 'L'){
                que.push(make_pair(nx, ny));
                visited[nx][ny] = visited[px][py] + 1;
            }
        }
    }

    return cnt-1;
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
            if(arr[i][j] == 'L'){
                result = max(result, Treasure(i, j));
            }
        }
    }

    cout << result;
}
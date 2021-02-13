// 아 맞다 우산
// 1194 - 달이 차오른다. 가자  >>> 이문제랑 거의 똑같아!
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M, startX, startY, cntX, result;
char arr[51][51];
int visited[51][51][1<<5]; // 방문했던 물건 위치 비트마스크로 저장
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

struct info{
    int x, y, k, cnt;
};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> M >> N;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j];
            if(str[j] == 'X'){ arr[i][j] = cntX++ + '0'; }
            else if(str[j] == 'S'){ startX = i; startY = j; }
        }
    }
    queue<info> que;
    que.push({startX, startY, 0, 0});
    visited[startX][startY][0] = 1;

    while (!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        int k = que.front().k;
        int cnt = que.front().cnt;
        que.pop();

        if(arr[x][y] == 'E' && k == (1 << cntX) - 1){
            result = cnt;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nk = k;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == '#'){ continue; }
            if(visited[nx][ny][nk]){ continue; }

            if(arr[nx][ny] >= '0' && arr[nx][ny] <= '4'){ nk |= (1 << (arr[nx][ny] - '0')); }
            visited[nx][ny][nk] = 1;
            que.push({nx, ny, nk, cnt + 1});
        }
    }

    cout << result;
    return 0;
}
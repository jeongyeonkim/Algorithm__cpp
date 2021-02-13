// 로봇
#include <iostream>
#include <queue>
using namespace std;
int N, M, result;
int arr[101][101], visited[101][101][5];
int dx[4] = {0, 1, 0, -1}; // 동 남 서 북
int dy[4] = {1, 0, -1, 0};
int start[3], goal[3];

struct info{
    int x, y, dir, cnt;
};
queue<info> que;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){ cin >> arr[i][j]; }
    }
    int k = 0;
    cin >> start[0] >> start[1] >> k;
    if(k == 1){ start[2] = 0; } // dir 동남서북 방향으로 바꿔줌
    else if(k == 2){ start[2] = 2; }
    else if(k == 3){ start[2] = 1; }
    else if(k == 4){ start[2] = 3; }
    que.push({start[0], start[1], start[2], 0});
    visited[start[0]][start[1]][start[2]] = 1;

    cin >> goal[0] >> goal[1] >> k;
    if(k == 1){ goal[2] = 0; }
    else if(k == 2){ goal[2] = 2; }
    else if(k == 3){ goal[2] = 1; }
    else if(k == 4){ goal[2] = 3; }

    while (true){
        int x = que.front().x;
        int y = que.front().y;
        int dir = que.front().dir;
        int cnt = que.front().cnt;
        que.pop();

        if(x == goal[0] && y == goal[1] && dir == goal[2]){ // 도착지점 + 방향일 경우 while문 탈출
            result = cnt;
            break;
        }

        for(int i=1; i<=3; i++){
            int nx = x + dx[dir]*i;
            int ny = y + dy[dir]*i;
            if(nx <= 0 || ny <= 0 || nx > N || ny > M || arr[nx][ny] == 1){ break; } // 범위를 넘어가거나, 1이 있을 경우 break
            if(visited[nx][ny][dir]){ continue; } // 이미 방문한 경우 continue
            que.push({nx, ny, dir, cnt + 1});
            visited[nx][ny][dir] = 1;
        }

        if(!visited[x][y][(dir + 1) % 4]){ // 오른쪽 회전
            que.push({x, y, (dir + 1) % 4, cnt + 1});
            visited[x][y][(dir + 1) % 4] = 1;
        }
        if(!visited[x][y][(dir + 3) % 4]){ // 왼쪽 회전
            que.push({x, y, (dir + 3) % 4, cnt + 1});
            visited[x][y][(dir + 3) % 4] = 1;
        }
        if(!visited[x][y][(dir + 2) % 4]){ // 반대방향 회전
            que.push({x, y, (dir + 2) % 4, cnt + 2}); // 반대방향일 경우 회전을 두 번 한것이니 때문에 cnt + 2
            visited[x][y][(dir + 2) % 4] = 1;
        }
    }
    cout << result;
    return 0;
}
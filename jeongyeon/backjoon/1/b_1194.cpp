// 달이 차오른다, 가자
// BFS + bitmask
// 방문 시 어떤 키를 가지고 있는지에 따라서 다른 값 나옴.
#include <iostream>
#include <queue>
using namespace std;
int N, M, result;
char arr[51][51];
int visited[51][51][64]; // a, b, c, d, e, f -> 열쇠 6개 2^6 = 64
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y, k;
};
queue<info> que;

int bfs(){
    while (!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        int k = que.front().k;
        que.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nk = k;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == '#' || visited[nx][ny][nk] != 0){  continue; }

            if(arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f'){ // 열쇠 추가
                nk |= (1 << arr[nx][ny] - 'a');
            }
            else if(arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F'){
                if(!(nk & (1 << arr[nx][ny] - 'A'))){ continue; } // 열쇠 없으면 continue
            }

            que.push({nx, ny, nk});
            visited[nx][ny][nk] = visited[x][y][k] + 1;
            if(arr[nx][ny] == '1'){ return visited[nx][ny][nk]; }
        }
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '0'){ que.push({i, j, 0}); }
        }
    }

    cout << bfs();
    return 0;
}
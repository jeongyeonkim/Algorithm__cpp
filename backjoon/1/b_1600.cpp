// 말이 되고픈 원숭이
#include <iostream>
#include <queue>
using namespace std;
int K, H, W, result = -1;
int arr[201][201], visited[31][201][201];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ddx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
int ddy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

struct info{
    int x, y, cnt, numK;
};

bool unbound(int x, int y){
    if(x < 0 || y < 0 || x >= H || y >= W || arr[x][y]){ return true; }
    return false;
}

void bfs(){
    queue<info> que;
    que.push({0, 0, 0, 0});
    visited[0][0][0] = 1;

    while (!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().cnt;
        int numK = que.front().numK;
        que.pop();

        if(x == H-1 && y == W-1){ result = cnt; break; }

        if(numK < K){
            for(int i=0; i<8; i++){
                int nnx = x + ddx[i];
                int nny = y + ddy[i];
                if(unbound(nnx, nny) || visited[numK+1][nnx][nny]){ continue; }
                
                visited[numK+1][nnx][nny] = 1;
                que.push({nnx, nny, cnt + 1, numK + 1});
            }
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(unbound(nx, ny) || visited[numK][nx][ny]){ continue; }

            visited[numK][nx][ny] = 1;
            que.push({nx, ny, cnt + 1, numK});
        }
    }   
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> K; cin >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){ cin >> arr[i][j]; }
    }

    bfs();

    cout << result;
    return 0;
}
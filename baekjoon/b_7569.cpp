// 토마토
#include <iostream>
#include <queue>
using namespace std;

struct tomato{
    int z;
    int x;
    int y;
};

int N, M, H, result, X, Y, Z;
int arr[101][101][101];
int dir[6][3] = {{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}};
queue<tomato>q;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // 입력
    cin >> M >> N >> H;
    bool check = false;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int z=0; z<M; z++){
                cin >> arr[i][j][z];
                if(arr[i][j][z] == 0){ check = true; }
                if(arr[i][j][z] == 1){
                    // 익은 토마토가 있을 경우 탐색 시작 위치 저장.
                    q.push({i, j, z});
                }
            }
        }
    }

    // 안익은 토마토가 없을 경우
    if(!check){ cout << 0; return 0;}

    while (!q.empty()){
        X = q.front().x;
        Y = q.front().y;
        Z = q.front().z;
        q.pop();

        for (int i=0; i<6; i++) {
            int nx = X + dir[i][1];
            int ny = Y + dir[i][2];
            int nz = Z + dir[i][0];

            if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;
            if (arr[nz][nx][ny]) continue;
            arr[nz][nx][ny] = arr[Z][X][Y] + 1;
            q.push({nz, nx, ny});
        }
    }

    // 안익은 토마토가 있을 경우
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int z=0; z<M; z++){
                if(arr[i][j][z] == 0){
                    cout << -1;
                    return 0;
                }
                if (result < arr[i][j][z]){ result = arr[i][j][z]; }
            }
        }
    }

    cout << result-1;
    return 0;
}
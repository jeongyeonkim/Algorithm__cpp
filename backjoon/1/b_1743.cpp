// 음식물 피하기
// DFS + 방문 체크를 이용해서 그룹화
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, n, m, result, food_size;
int food[101][101], visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void avoidFood(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || ny <= 0 || nx > N || ny > M){ continue; }

        if(food[nx][ny] == 1 && visited[nx][ny] == 0){
            food_size++;
            visited[nx][ny] = 1;
            avoidFood(nx, ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=K; i++){
        cin >> n >> m;
        food[n][m] = 1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(food[i][j] == 1 && visited[i][j] == 0){
                food_size = 1;
                visited[i][j] = 1;
                avoidFood(i, j);
                result = max(result, food_size);
            }
        }
    }

    cout << result;
    return 0;
}
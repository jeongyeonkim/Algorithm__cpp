// 치즈
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int arr[101][101], visited[101][101];
int N, M, result, resultDay;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y;
};

int cntCheese(){ // 치즈 갯수 구하기
    int cnt = 0;
    for(int i=1; i<N-1; i++){
        for(int j=1; j<M-1; j++){
            if(arr[i][j] == 1){ cnt++; }
        }
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> arr[i][j]; }
    }

    while (true){
        int cnt = cntCheese();
        if(cnt == 0){ break; }
        else{ result = cnt; }

        queue<info> que;
        memset(visited, 0, sizeof(visited));
        visited[0][0] = visited[0][M-1] = visited[N-1][0] = visited[N-1][M-1] = 1;
        for(int i=0; i<N; i++){ 
            for(int j=0; j<M; j++){
                if(i == 0 || i == N-1 || j == 0 || j == M-1){ // 배열 외각에서 부터 시작해서 처음 닿는 arr[][] = 1인 곳이 외각 치즈
                    visited[i][j] = 1;
                    que.push({i, j});
                }
            }
        }

        while (!que.empty()){
            int x = que.front().x;
            int y = que.front().y;
            que.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]){ continue; }

                if(arr[nx][ny] == 1){ arr[nx][ny] = 0; } // 외각 치즈일 경우 0을 바꿔줌
                else{ que.push({nx, ny}); }
                visited[nx][ny] = 1;
            }
        }
        resultDay++;
    }
    
    cout << resultDay << "\n" << result;
    return 0;
}
// 빙산
#include <iostream>
#include <string.h>
using namespace std;
int N, M, result;
int arr[301][301], temp[301][301], visited[301][301];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y){ // 영역 구하는 dfs
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 | nx >= N || ny >= M){ continue; }
        if(visited[nx][ny] || arr[nx][ny] <= 0){ continue; }

        visited[nx][ny] = 1;
        dfs(nx, ny);
    }
}

void melt(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] > 0){
                if(arr[i][j] < temp[i][j]){ arr[i][j] = 0; }
                else{ arr[i][j] -= temp[i][j]; }
            }
        }
    }
}

int cntZero(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
        if(arr[nx][ny] == 0){ cnt++; }
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
        int visit_cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] > 0 && visited[i][j] == 0){ // 영역 구하기
                    visit_cnt++;
                    visited[i][j] = 1;
                    dfs(i, j);
                }
            }
        }

        if(visit_cnt == 0){ result = 0; break; } // 모두 다 녹아서 덩어리가 없을 경우 result = 0 반환
        else if(visit_cnt >= 2){ break; } // 두 덩어리 이상 쪼개졌을 경우

        memset(temp, 0, sizeof(temp));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] > 0){ temp[i][j] = cntZero(i, j); } // 네방향 0의 개수 구해서 temp에 저장
            }
        }

        melt(); // 녹는 갯수 arr에 반영
        result++;
    }

    cout << result;
    return 0;
}
// Two Dots
#include <iostream>
#include <string.h>
using namespace std;
int N, M;
char arr[51][51];
int visited[51][51];
bool check; // 이미 사이클이 형성될 수 있으면 break나 return하려고 사용
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void dfs(int x, int y, int X, int Y, int cnt){
    if(check){ return; }
    if(x == X && y == Y && cnt >= 4){ check = true; return; } // 시작 지점에 도착할 경우 사이클 형성 완료

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
        if(arr[nx][ny] == arr[X][Y] && visited[nx][ny] == 0){
            visited[nx][ny] = 1;
            dfs(nx, ny, X, Y, cnt + 1);
            visited[nx][ny] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++){ arr[i][j] = str[j]; }
    }
    
    for(int i=0; i<N; i++){ // 모든 지점에서 시작해서 사이클 만들어 지는지 체크
        for(int j=0; j<M; j++){
            memset(visited, 0, sizeof(visited));
            check = false;
            dfs(i, j, i, j, 1);
            if(check){ break; }
        }
        if(check){ break; }
    }
    if(check){ cout << "Yes"; }
    else{ cout << "No"; }
    return 0;
}
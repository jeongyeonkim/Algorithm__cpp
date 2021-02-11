// 치즈
// 1. tmpCheeze에 1시간 후 치즈 상태 저장
// 2. 인접한 자리에 치즈가 없을 경우 dfs 타면서 벽 만나는지 확인 >> visit 체크
// 3. 1. 실행 시 안녹은 치즈가 1개라도 있을 경우 while문 계속 루프
#include <iostream>
#include <string.h>
using namespace std;
int N, M, resultTime;
int cheeze[101][101], tmpCheeze[101][101], visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check, existCheeze;

void copyCheeze(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cheeze[i][j] = tmpCheeze[i][j]; }
    }
}

void checkOutside(int x, int y){
    if(!check) { return; }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || ny <= 0 || nx >= N-1 || ny >= M-1){
            check = false;
            return;
        }
        if(cheeze[nx][ny] == 0 && visited[nx][ny] == 0){
            visited[nx][ny] = 1;
            checkOutside(nx, ny);
        }
    }
}

bool adjCheeze(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(cheeze[nx][ny] == 0){
            check = true;
            memset(visited, 0, sizeof(visited));
            visited[nx][ny] = 1;
            checkOutside(nx, ny);
            if(!check){ cnt++; }
        }
        if(cnt >= 2){ return false; }
    }
    return true;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> cheeze[i][j]; }
    }
    
    while (true) {
        memset(tmpCheeze, 0, sizeof(tmpCheeze));
        existCheeze = false;

        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){
                if(cheeze[i][j] == 1 && adjCheeze(i, j)){
                    tmpCheeze[i][j] = 1;
                    existCheeze = true;
                }
            }
        }

        resultTime++;
        if(!existCheeze){ break; }
        copyCheeze();
    }

    cout << resultTime;
    return 0;
}
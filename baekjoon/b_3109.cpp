// 빵집
#include <iostream>
using namespace std;
int R, C, result;
int dx[3] = {-1, 0, 1};
char breadStore[10001][501];
// 1. 그리디 사용 >> 위 옆 아래 순으로 -> 위에부터 파이프 탐색을 하기 때문에
// 2. visited 방문 상태  저장
// 3. 백트래킹 x > 이미 방문한 곳에 또 방문하더랃도 같은 결과


// 104ms 6908KB
bool pipe(int x, int y){
    bool ret = false;
    if(y == C - 1) { return true; }

    for(int i=0; i<3; i++){
        int nx = x + dx[i];
        int ny = y + 1;

        if(nx < 0 || nx >= R){ continue; }
        if(breadStore[nx][ny] == 'x') { continue; }
        breadStore[nx][ny] = 'x';
        if(pipe(nx, ny)){
            return true;
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){ cin >> breadStore[i][j]; }
    }

    for(int i=0; i<R; i++){
        if(pipe(i, 0)){
            result++;
        }
    }

    cout << result;
    return 0;
}
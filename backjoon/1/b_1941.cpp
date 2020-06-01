//소문난 칠공주
#include <iostream>
#include <string.h>
using namespace std;
int result;
int arr[6][6], visited[6][6], selected[8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void visit(int x, int y){
    visited[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny] == 0){ continue; }
        visit(nx, ny);
    }
}

void check(){
    memset(visited, 0, sizeof(visited));
    bool ck = false;
    for(int i=0; i<7; i++){ visited[selected[i]/5][selected[i]%5] = 1; }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(visited[i][j]){
                if(ck){ return; }
                ck = true;
                visit(i, j);
            }
        }
    }
    result++;
}

void dfs(int cnt, int cntS, int cntY){
    if(cntY > 3){ return; }
    if(cnt == 7){ check(); return; } // 멤버가 다 모이면 인접해 있는지 체크

    for(int i=cntS; i<25; i++){
        selected[cnt] = i;
        
        if(arr[i/5][i%5] == 1){ // 이다솜파
            dfs(cnt + 1, i + 1, cntY);
        }
        else{ // 임도연파
            dfs(cnt + 1, i + 1, cntY + 1);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<5; i++){
        string str; cin >> str;
        for(int j=0; j<5; j++){
            if(str[j] == 'S'){ arr[i][j] = 1; }
        }
    }

    dfs(0, 0, 0);
    cout << result;
    return 0;
}
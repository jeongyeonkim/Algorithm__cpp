// 양치기 꿍
#include <iostream>
using namespace std;
int sheep, wolf, s, w;
int R, C;
int arr[251][251], visited[251][251];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y){
    if(arr[x][y] == -1){ w++; }
    else if(arr[x][y] == 1){ s++; }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >=R || ny < 0 || ny >= C){ continue; }
        if(visited[nx][ny] == 0 && arr[nx][ny] != 2){
            visited[nx][ny] = 1; 
            DFS(nx, ny);
        }
    }
}

void input(int x, int y, char a){
    if(a == '#'){ arr[x][y] = 2; return; }
    if(a == 'v'){ arr[x][y] = -1; return; }
    if(a == 'k'){ arr[x][y] = 1; return; }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char a; cin >> a;
            input(i, j, a);
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(visited[i][j] == 0 && arr[i][j] != 2){
                visited[i][j] = 1;
                DFS(i, j);
                
                if(s > w){ w = 0; }
                else{ s = 0; }
                sheep += s;
                wolf += w;
                s = w = 0;
            }
        }
    }   

    cout << sheep << " " << wolf;
}
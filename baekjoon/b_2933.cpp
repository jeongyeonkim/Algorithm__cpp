// 미네랄
#include <iostream>
#include <algorithm>
using namespace std;
int R, C, N, dir = 1;
int arr[101][101], visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int flag;

bool unbound(int x, int y){
    if(x <= 0 || y <= 0 || x > R || y > C){ return true; }
    return false;
}

void move(){
    
}

void moveCheck(){
    bool able[C+1];
    int cnt = R;
    memset(able, 0, sizeof(able));
    for(int i=R; i>0; i--){
        for(int j=1; j<C; j++){
            if(!able[j] && !visited[i][j]){
                
            }
        }
    }
}

void dfs(int x, int y){
    if(x == R){ flag = false; return; }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(unbound(nx, ny)){ continue; }
        if(!visited[nx][ny] && arr[nx][ny]){ dfs(nx, ny); }
    }
}

void minaral(int K, int d){
    int x = R - K;
    int y;
    bool check = true;
    if(d == 1){
        y = 1;
        while (true){
            if(y > C){ check = false; break; }
            if(arr[x][y] == 1){ break; }
            y++;
        }
    }
    else{
        y = C;
        while (true){
            if(y < 1){ check = false; break; }
            if(arr[x][y] == 1){ break; }
            y--;
        }
    }

    if(check){
        arr[x][y] = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(unbound(nx, ny)){ continue; }
            if(arr[nx][ny] == 1){
                flag = true;
                memset(visited, 0, sizeof(visited));
                dfs(nx, ny);
                if(flag){
                    
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            char a; cin >> a;
            if(a == 'X'){ arr[i][j] = 1; }
        }
    }
    cin >> N;
    for(int i=0; i<N; i++){
        int k; cin >> k;
        minaral(k, dir);
        dir *= -1;
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(arr[i][j] == 0){ cout << ". "; }
            else{ cout << "X "; }
            cout << "\n";
        }
    }
}
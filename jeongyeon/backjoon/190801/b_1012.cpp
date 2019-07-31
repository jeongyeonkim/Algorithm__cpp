#include <iostream>
#include <cstring>
using namespace std;
int input[51][51];
int visit[51][51];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
int N, M, L;

void DFS(int x, int y){
    visit[x][y] =1;
    for(int i=0; i<4; i++){
        int nx = x +dx[i], ny = y +dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M ){
            if (visit[nx][ny] == 0 && input[nx][ny] == 1){
                DFS(nx, ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T=0; cin >> T;

    for(int k=0; k<T; k++){
        int cnt=0;
        memset(input, 0, sizeof(input));
        memset(visit, 0, sizeof(visit));
        cin >> M >> N >> L;
        for(int i=0; i<L; i++){
            int a=0,b =0; cin >> a >> b;
            input[b][a] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(input[i][j] == 1 && visit[i][j] == 0){
                    DFS(i, j);
                    cnt++;
                }
            } 
        }
        cout << cnt << "\n";
    }
    return 0;
}
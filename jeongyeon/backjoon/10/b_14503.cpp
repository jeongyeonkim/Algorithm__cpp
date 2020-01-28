// 로봇 청소기
#include <iostream>
using namespace std;
int N, M, r, c, d, cnt;
int arr[51][51];
bool clean;
// 북, 동, 남, 서 
int leftD1[4] = {0, -1, 0, 1};
int leftD2[4] = {-1, 0, 1, 0};
int backD1[4] = {1, 0, -1, 0};
int backD2[4] = {0, -1, 0, 1};

int turn(int dir){
    if(dir == 0) return 3;
    else return dir-1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> arr[i][j]; }
    }

    if(arr[r][c] == 0){
        cnt++;
        arr[r][c] = -1;
    }  

    while(true){
        clean = false;
        int lx = r + leftD1[d];
        int ly = c + leftD2[d];
        int bx = r + backD1[d];
        int by = c + backD2[d];

        for(int i=0; i<4; i++){
            if(lx < N && lx >= 0 && ly < M && ly >= 0 && arr[r+leftD1[i]][c+leftD2[i]] == 0){
                clean = true;
            }
        }

        if(clean){
            if(arr[lx][ly] == 0){
                cnt++;
                d = turn(d);
                r = lx;
                c = ly;
                arr[r][c] = -1;
            }else{
                d = turn(d);
            }
        }else{
            if(arr[bx][by] == 1){ break; }
            r = bx;
            c = by;
        }
    }

    cout << cnt;
}
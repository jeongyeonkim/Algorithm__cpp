// 미세먼지 안녕!
#include <iostream>
#include <string.h>
using namespace std;
int R, C, T, d;
int arr[51][51], addArr[51][51];
pair<int, int> air[2];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool bound(int x, int y){ // 범위 체크
    if(x < 0 || y < 0 || x >= R || y >= C){ return false; }
    return true;
}

int cntMicro(){ // 남은 미세먼지 수 세기
    int res = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] != 0 && arr[i][j] != -1){
                res += arr[i][j];
            }
        }
    }
    return res;
}

void bye(){
    memset(addArr, 0, sizeof(addArr));

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] > 0){ // 미세먼지 확산
                int cnt = 0;
                for(int d=0; d<4; d++){
                    int nx = i + dx[d]; int ny = j + dy[d];
                    if(bound(nx, ny) && arr[nx][ny] != -1){ // 벽이 아니거나 공기청정기 있는 곳이 아닐경우 확산 가능 지역
                        cnt++;
                        addArr[nx][ny] += arr[i][j]/5;
                    }
                }
                addArr[i][j] -= cnt*(arr[i][j]/5);
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){ arr[i][j] += addArr[i][j]; }
    }

    for(int i=0; i<2; i++){ // 공기청정기 작동
        d = 0;
        int nx = air[i].first, ny = air[i].second;
        int tempB = 0, tempC = 0;

        while(true){
            nx += dx[d];
            ny += dy[d];
            if(nx == air[i].first && ny == air[i].second){ break; } // 바람이 시작점으로 돌아오면 Break

            if(!bound(nx, ny)){ // 벽에 부딪히면 방향 바꾸어줌
                nx -= dx[d]; ny -= dy[d];
                if(i == 0){ d = (d + 1) % 4; }
                else{ d = (d + 3) % 4; }
            }
            else{
                tempC = arr[nx][ny];
                arr[nx][ny] = tempB;
                tempB = tempC;
            }
        }   
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C >> T;
    int airCnt = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1){
                air[airCnt++] = make_pair(i, j);
            }
        }
    }

    while (T--){ bye();}
    
    cout << cntMicro() << "\n";
    return 0;
}
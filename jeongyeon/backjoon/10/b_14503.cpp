// 로봇 청소기
#include <iostream>
using namespace std;
int N, M, r, c, d, cnt;
int arr[51][51];
bool clean;
// 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

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
        int lx = r + dx[(d+3)%4];
        int ly = c + dy[(d+3)%4];
        int bx = r + (dx[d])*(-1);
        int by = c + (dy[d])*(-1);

        for(int i=0; i<4; i++){
            // 범위 내에 있으면서 청소 가능한 구역 있으면 clean = true로 바꿈.
            if(lx < N && lx >= 0 && ly < M && ly >= 0 && arr[r+dx[(i+3)%4]][c+dy[(i+3)%4]] == 0){
                clean = true;
            }
        }

        if(clean){
            // 왼쪽이 청소 가능할 경우
            if(arr[lx][ly] == 0){
                cnt++;
                d = (d+3)%4;
                r = lx;
                c = ly;
                arr[r][c] = -1;
            }else{ // 왼쪽이 청소가 되어있거나 다른 방향이 청소 가능하나 곳이 있을 경우 방향만 회전
                d = (d+3)%4;
            }
        }else{ // 청소가능한 곳이 없거나 벽인 경우
            if(arr[bx][by] == 1){ break; } // 후진 가능하지 않는 경우 while문 탈출
            r = bx;
            c = by;
        }
    }

    cout << cnt;
    return 0;
}
// [모의 SW 역량테스트] 줄기세포배양
#include <iostream>
#include <queue>
using namespace std;
int T, result, N, M, K, input;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

struct cell{
    int state; // -1 = 빈칸, 0 = 비활성, 1 = 활성, 2 = 죽음
    int life;
    int active;
    int unactive;
} arr[351][351];

void spreadCell(){
    while (K--){
        queue<pair <int, int> > que;

        for(int i=0; i<=350; i++){
            for(int j=0; j<=350; j++){
                if(arr[i][j].state == 0){ // 비활성일떄
                    arr[i][j].unactive--;
                    if(arr[i][j].unactive == 0){ arr[i][j].state = 1; } // 비활성 시간이 끝나면 세포 상태 활성으로 바꿈
                }else if(arr[i][j].state == 1){ // 활성일때
                    que.push(make_pair(i, j)); // 활성 일때는 상하좌우로 퍼져야 하기 때문에 que에 넣어줌
                    arr[i][j].active--;
                    if(arr[i][j].active == 0){ arr[i][j].state = 2; } // 활성 시간이 끝나면 세포 죽음
                }
            }
        }

        while (!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(arr[nx][ny].state == -1){
                    cell newCell = {0, arr[x][y].life, arr[x][y].life, arr[x][y].life};
                    arr[nx][ny] = newCell;
                }
                else if(arr[nx][ny].state == 0 && arr[nx][ny].life == arr[nx][ny].unactive){
                    if(arr[nx][ny].life < arr[x][y].life){
                        cell changeCell = {0, arr[x][y].life, arr[x][y].life, arr[x][y].life};
                        arr[nx][ny] = changeCell;
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(int test_case = 1; test_case <= T; ++test_case){
        cin >> N >> M >> K;
        cell init = {-1, 0, 0, 0};
        for(int i=0; i<=350; i++){
            for(int j=0; j<=350; j++){ arr[i][j] = init; }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> input;
                if(input > 0){
                    cell c = {0, input, input, input};
                    arr[i+150][j+150] = c;
                }
            }
        }

        spreadCell();

        for(int i=0; i<=350; i++){
            for(int j=0; j<=350; j++){ // result = 비활성 세포 수 + 활성 세포 수
                if(arr[i][j].state == 0 || arr[i][j].state == 1){ result++; }
            }
        }
        
        cout << "#" << test_case << " " << result << "\n"; 
        result = 0;
    }
    return 0;
}
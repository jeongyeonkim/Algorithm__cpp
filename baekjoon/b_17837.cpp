// 새로운 게임 2
#include <iostream>
#include <vector>
using namespace std;
int N, K, result, a, b, c;
int arr[13][13], info[13][3];
vector<int> horse[13][13]; // horse info -> 0 = x좌표, 1 = y 좌표, 2 = 방향
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int oppDir[5] = {0, 2, 1, 4, 3};
bool roop = false;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){ cin >> arr[i][j]; }
    }
    for(int i=1; i<=K; i++){
        cin >> a >> b >> c;
        horse[a][b].push_back(i);
        info[i][0] = a;
        info[i][1] = b;
        info[i][2] = c;
    }

    while(true){
        result++;
        for(int i=1; i<=K; i++){
            int x = info[i][0], y = info[i][1];

            int nx = x + dx[info[i][2]];
            int ny = y + dy[info[i][2]];

            if(nx <= 0 || ny <= 0 || nx > N || ny > N || arr[nx][ny] == 2){ // 파란색이거나 체스판 밖으로 나갈 경우
                info[i][2] = oppDir[info[i][2]]; // 반대 방향으로 바꿈
                nx = x + dx[info[i][2]];
                ny = y + dy[info[i][2]];
                if(nx <= 0 || ny <= 0 || nx > N || ny > N ||arr[nx][ny] == 2){ continue; } // 방향 바꿔서 이동한 곳도 파란색이면 continue
            }

            bool check = false;
            if(arr[nx][ny] == 0){ // 흰색일 경우
                int cnt = 0;
                for(int h=0; h<horse[x][y].size(); h++){
                    if(horse[x][y][h] == i || check){
                        cnt++;
                        check = true;
                        horse[nx][ny].push_back(horse[x][y][h]);
                        info[horse[x][y][h]][0] = nx;
                        info[horse[x][y][h]][1] = ny;
                    }
                }
                for(int h=0; h<cnt; h++){ horse[x][y].pop_back(); }
            }

            else if(arr[nx][ny] == 1){// 빨간색일 경우 
                for(int h=horse[x][y].size()-1; h>=0; h--){
                    if(horse[x][y][h] == i || !check){

                        if(horse[x][y][h] == i){ check = true; }
                        horse[nx][ny].push_back(horse[x][y][h]);
                        info[horse[x][y][h]][0] = nx;
                        info[horse[x][y][h]][1] = ny;
                        horse[x][y].pop_back();
                    }
                }
            }

            if(horse[nx][ny].size() >= 4){ roop = true; } // 한 칸에 모든 말이 있을 경우 게임 종료
        }
        if(roop){ break; }
        if(result >= 1000){ break; }
    }
    if(result >= 1000){ result = -1; }
    cout << result;
    return 0;
}
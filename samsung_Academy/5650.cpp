// [모의 SW 역량테스트] 핀볼 게임
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int test_case, T, result, N, X, Y;
int arr[102][102];
vector<pair <int, int> > worm[12], startP;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dir[6][4] = {{}, {2, 0, 3, 1}, {2, 3, 1, 0}, {1, 3, 0, 2}, {3, 2, 0, 1}, {2, 3, 0, 1}}; // 블록 마다 바뀌는 방향

bool bound(int x, int y){
    if(x <= 0 || y <= 0 || x > N || y > N){ return false; }
    return true;
}

void pinball(int x, int y, int d){
    int cnt = 0;

    while (true){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx == X && ny == Y){ // 처음 시작 점 만났을 경우 게임 아웃
            result = max(result, cnt);
            return;
        }
        
        if(!bound(nx, ny)){ // 벽을 만났을 경우 방향 반대
            d = (d + 2) % 4;
            cnt++;
        }

        else if(arr[nx][ny] >= 1 && arr[nx][ny] <= 5){ // 1~5번 블록을 만났을 경우
            d = dir[arr[nx][ny]][d];
            cnt++;
        }

        else if(arr[nx][ny] >= 6 && arr[nx][ny] <= 10){ // 웜홀을 만났을 경우
            int block = arr[nx][ny];
            if(nx == worm[block][0].first && ny == worm[block][0].second){ // 반대면 웜홀으로 nx, ny 이동
                nx = worm[block][1].first;
                ny = worm[block][1].second;   
            }else{
                nx = worm[block][0].first;
                ny = worm[block][0].second;
            }
        }

        else if(arr[nx][ny] == -1){ // 블랙홀을 만났을 경우 게임 아웃
            result = max(result, cnt);
            return;
        }
        x = nx; y = ny;
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> arr[i][j];
                if(arr[i][j] >= 6 && arr[i][j] <= 10){
                    worm[arr[i][j]].push_back(make_pair(i, j));
                }else if(arr[i][j] == 0){ // 가능한 시작 점
                    startP.push_back(make_pair(i, j));
                }
            }
        }

        for(int i=0; i<startP.size(); i++){ // 모든 시작점 & 모든 방향으로 브루트 포스
            for(int j=0; j<4; j++){
                X = startP[i].first; Y = startP[i].second;
                pinball(X, Y, j);
            }
        }

        cout << "#" << test_case << " " << result << "\n"; 
        memset(arr, 0, sizeof(arr));
        result = 0;
        startP.clear();
        for(int i=0; i<11; i++){ worm[i].clear(); }
    }
    return 0;
}
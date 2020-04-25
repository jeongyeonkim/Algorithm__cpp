// [모의 SW 역량테스트] 홈 방범 서비스
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int test_case, T, N, M, result;
int map[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int cost(int k, int h){ return (M*h) - (k*k+(k-1)*(k-1)); } // H = 집 갯수
bool bound(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N){ return false; }
    return true;
}

void homeCnt(int x, int y){
    int cnt[N+2]; // map 전체의 경우도 탐색해야하기 때문에 N+1까지 탐색
    memset(cnt, 0, sizeof(cnt));
    if(map[x][y] == 1){ cnt[1]++; }

    for(int i=2; i<=N+1; i++){
        cnt[i] += cnt[i-1];

        for(int j=1; j<i-1; j++){ // 한칸 씩 위 아래로 가면서 양 옆 체크
            for(int k=2; k<4; k++){
                int nx = x + dx[k]*j;
                int ny = y + dy[0]*(i-1-j);
                int ny2 = y + dy[1]*(i-1-j);

                if(bound(nx, ny) && map[nx][ny] == 1){ cnt[i]++; }
                if(bound(nx, ny2) && map[nx][ny2] == 1){ cnt[i]++; }
            }
        }

        for(int j=0; j<4; j++){
            int nx = x + dx[j]*(i-1);
            int ny = y + dy[j]*(i-1);

            if(bound(nx, ny) && map[nx][ny] == 1){ cnt[i]++; }
        }
    }

    for(int i=1; i<=N+1; i++){
        if(cost(i, cnt[i]) >= 0){ result = max(result, cnt[i]); } 
    }
}

int main(int argc, char** argv){
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ cin >> map[i][j]; }
        }

        for(int i=0; i<N; i++){ // 브루트 포스
            for(int j=0; j<N; j++){ homeCnt(i, j); }
        }

        cout << "#" << test_case << " " << result << "\n"; 
        memset(map, 0, sizeof(map));
        result = N = M = 0;
    }
    return 0;
}
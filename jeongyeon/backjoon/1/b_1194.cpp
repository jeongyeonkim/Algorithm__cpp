// 달이 차오른다, 가자
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, result = 1e9;
char arr[51][51];
pair<int, int> start, goal;
int dp[51][51][1<<24];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void tsp(int x, int y, int visited){
    if(arr[x][y] == '1'){
        result = min(result, dp[x][y][visited]);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int num = 0;
        bool check = false;

        if(nx < 0 || ny < 0 || nx >=N || ny >= M || arr[nx][ny] == '#'){ continue; }
        if(arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z'){
            for(int j=0; j<24; j++){
                if(arr[nx][ny]-65 == j){ check = true; }
            }
        }
        if(!check){ continue; }
        if(arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z'){
            num = arr[nx][ny] - 97;
        }
        if(dp[nx][ny][visited + num] != 0){ continue; }
        dp[nx][ny][visited + num] = dp[x][y][visited] + 1;
        tsp(nx, ny, visited + num);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '0'){ start = make_pair(i, j); }
        }
    }
    memset(dp, -1, sizeof(dp));
    tsp(start.first, start.second, 0);
    if(result == 1e9){ result = -1; }
    cout << result;
    return 0;
}
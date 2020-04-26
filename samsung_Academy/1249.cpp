// [S/W 문제해결 응용] 4일차 - 보급로
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int test_case, T, N;
int arr[101][101], temp[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Route(){
    queue<pair <int, int> > que;
    que.push(make_pair(0, 0));

    while (!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++){
            int nx = x+ dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N){ continue; }
            if(!visited[nx][ny] || temp[nx][ny] > temp[x][y] + arr[nx][ny]){
                temp[nx][ny] = temp[x][y] + arr[nx][ny];
                visited[nx][ny] = true;
                que.push(make_pair(nx, ny));
            }
        }
    }
    
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin  >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ scanf("%1d", &arr[i][j]); }
        }

        Route();

        cout << "#" << test_case << " " << temp[N-1][N-1] << "\n"; 
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        memset(temp, 0, sizeof(temp));
    }
    return 0;
}



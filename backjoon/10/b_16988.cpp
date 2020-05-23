// Baaaaaaaaaduk2 (Easy)
// 연구소 문제랑 비슷함
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, result, temp;
int arr[21][21], visited[21][21];
bool check;
vector<pair <int, int>> selected;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y){
    visited[x][y] = 1;
    temp++;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
        if(arr[nx][ny] == 0){ check = false;} // 주위에 0을 만나는 순간 쓸모없는 구역이니까 check = false
        if(arr[nx][ny] == 1 || visited[nx][ny] == 1){ continue; }

        dfs(nx, ny);
    }
}

int Baduk(){
    memset(visited, 0, sizeof(visited));
    int res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 2 && visited[i][j] == 0){ // 아직 방문하지 않았으면서 arr가 2인 곳 탐색 시작
                check = true; temp = 0;
                dfs(i, j);
                if(check){ res += temp; } // 주위에 다 막혀있을 때만 더하기!
            }
        }
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){ selected.push_back(make_pair(i, j)); }
        }
    }
    for(int i=0; i<selected.size()-1; i++){ // 1을 넣을 곳 조합
        arr[selected[i].first][selected[i].second] = 1;
        for(int j=i+1; j<selected.size(); j++){
            arr[selected[j].first][selected[j].second] = 1;
            result = max(result, Baduk());
            arr[selected[j].first][selected[j].second] = 0;
        }
        arr[selected[i].first][selected[i].second] = 0;
    }

    cout << result;
    return 0;
}
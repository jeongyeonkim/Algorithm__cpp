// 연구소 3
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int N, M, result = 1e9, k;
int arr[51][51], dist[51][51];
bool selected[11];
vector<pair <int, int> > virus;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void spread(){
    memset(dist, -1, sizeof(dist));
    int times = 0, infect = 0;

    queue<pair <int, int> > que;
    for(int i=0; i<virus.size(); i++){
        if(selected[i]){
            que.push(make_pair(virus[i].first, virus[i].second));
            dist[virus[i].first][virus[i].second] = 0;
        }
    }

    while (!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
            if(arr[nx][ny] != 1 && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                if(arr[nx][ny] == 0){
                    infect++;
                    times = dist[nx][ny];
                }
                que.push(make_pair(nx, ny));
            }
        }

        if(infect == k && result > times){ result = times; }
    }
}

void selectVirus(int idx, int cnt){
    if(cnt >= M){
        spread();
        return;
    }

    for(int i = idx; i<virus.size(); i++){
        if(!selected[i]){
            selected[i] = true;
            selectVirus(i + 1, cnt + 1);
            selected[i] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){ virus.push_back(make_pair(i, j)); }
            else if(arr[i][j] == 0){ k++; }
        }
    }

    selectVirus(0, 0);

    if(result == 1e9){ cout << -1; }
    else{ cout << result; }
    return 0;
}
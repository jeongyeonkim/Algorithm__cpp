// 모래성
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, M, result;
int arr[1001][1001];
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
queue<pair <int, int> > pos;

bool castle(){
    int s = pos.size();
    for(int i=0; i<s; i++){
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();

        for(int j=0; j<8; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
            if(arr[nx][ny] > 0){ // 파도가 깍을 수 있는 모래성 -1
                arr[nx][ny]--;
                if(!arr[nx][ny]){ // 아예 없어지는 곳이면 파도에 push
                    pos.push(make_pair(nx, ny));
                }
            }
        }

    }
    if(pos.empty()){ return false; }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++){
            if(str[j] != '.'){
                arr[i][j] = str[j] - '0';
            }else{
                pos.push(make_pair(i, j));
            }
        }
    }

    while (castle()){ result++; }
    cout << result;
    return 0;
}
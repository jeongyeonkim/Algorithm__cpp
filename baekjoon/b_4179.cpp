// 불!
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int R, C, resultTime;
string input;
int _map[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Info{
    int x, y;
};
queue<Info> que_fire, que_J;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> input;
        for(int j=0; j<C; j++){
            if(input[j] == '#'){ _map[i][j] = 1; }
            else if(input[j] == 'J'){ que_J.push({i, j}); }
            else if(input[j] == 'F'){
                _map[i][j] = 1;
                que_fire.push({i, j});
            }
        }
    }

    int cnt = 0;
    while (true){
        cnt++;
        int queSize_fire = que_fire.size();
        if(resultTime != 0){ break; }
        while (queSize_fire--){
            int x = que_fire.front().x;
            int y = que_fire.front().y;
            que_fire.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C || _map[nx][ny] == 1){ continue; }
                _map[nx][ny] = 1;
                que_fire.push({nx, ny});
            }
        }

        int queSize_J = que_J.size();
        if(queSize_J == 0){ break; }
        while (queSize_J--){
            int x = que_J.front().x;
            int y = que_J.front().y;
            que_J.pop();

            if(x < 0 || y < 0 || x > R-1 || y > C-1){
                resultTime = cnt;
                break;
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i]; 
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C){
                    resultTime = cnt;
                    break;
                }
                if(_map[nx][ny] == -1 || _map[nx][ny] == 1){ continue; }
                _map[nx][ny] = -1;
                que_J.push({nx, ny});
            }
        }
    }
    
    if(resultTime == 0){ cout << "IMPOSSIBLE"; }
    else{ cout << resultTime; }
    return 0;
}
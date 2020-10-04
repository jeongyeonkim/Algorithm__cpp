// 불!
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int R, C, resultTime;
string input;
char _map[1001][1001], tmpMap[1001][1001];;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
pair<int, int> startJ;

struct Info{
    int x, y;
};

void spreadFire(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(_map[i][j] == 'F'){
                tmpMap[i][j] = 'F';
                for(int d=0; d<4; d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(ni < 0 || nj < 0 || ni >= R || nj >= C){ continue; }
                    if(_map[ni][nj] == '.'){ tmpMap[ni][nj] = 'F'; }
                }
            }
            else if(_map[i][j] == 'J'){ tmpMap[i][j] = 'J'; }
            else if(_map[i][j] == '#'){ tmpMap[i][j] = '#'; }
            else if(_map[i][j] == '.'){ tmpMap[i][j] = '.'; }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){ _map[i][j] = tmpMap[i][j]; }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> input;
        for(int j=0; j<C; j++){
            if(input[j] == 'J'){ startJ = {i, j}; }
            _map[i][j] = input[j];
        }
    }
    queue<Info> que;
    que.push({startJ.first, startJ.second});
    int cnt = 0;

    while (!que.empty()){
        int queSize = que.size();
        cnt++;
        bool flag = false;
        spreadFire();

        for(int i=0; i<queSize; i++){
            int x = que.front().x;
            int y = que.front().y;
            que.pop();

            if(x <= 0 || y <= 0 || x >= R-1 || y >= C-1){
                flag = true;
                resultTime = cnt;
                break;
            }

            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C ){ continue; }
                if(_map[nx][ny] == '.'){
                    que.push({nx, ny});
                    _map[nx][ny] = 'J';
                }
            }
        }
        if(flag){ break; }
    }
    
    if(resultTime == 0){ cout << "IMPOSSIBLE"; }
    else{ cout << resultTime; }
    return 0;
}
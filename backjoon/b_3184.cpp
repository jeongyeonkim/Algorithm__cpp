// 양
#include <iostream>
#include <string>
using namespace std;
int R, C, sheep, wolf, tmpSheep, tmpWolf;
string input;
char _map[251][251];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void fight(int x, int y){
    if(_map[x][y] == 'v'){ tmpWolf++; }
    else if(_map[x][y] == 'o'){ tmpSheep++; }
    _map[x][y] = '0';

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= R || ny >= C || _map[nx][ny] == '#'){ continue; }
        if(_map[nx][ny] != '0'){ fight(nx, ny); }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> input;
        for(int j=0; j<C; j++){ _map[i][j] = input[j]; }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(_map[i][j] == 'v' || _map[i][j] == 'o'){
                tmpSheep = 0; tmpWolf = 0;
                fight(i, j);

                if(tmpSheep > tmpWolf){ sheep += tmpSheep; }
                else{ wolf += tmpWolf; }
            }
        }
    }

    cout << sheep << " " << wolf;
    return 0;
}
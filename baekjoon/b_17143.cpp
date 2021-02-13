// 낚시왕
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int result, R, C, M, r, c, s, d, z;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int s, d, z;
};
info shark[101][101], tmp_shark[101][101];

int change_dir(int n){
    if(n == 1){ return 3; }
    if(n == 2){ return 1; }
    if(n == 3){ return 0; }
    if(n == 4){ return 2; }
}

void copy_shark(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            shark[i][j] = {tmp_shark[i][j].s, tmp_shark[i][j].d, tmp_shark[i][j].z};
        }
    }
}

void move_shark(){
    memset(tmp_shark, 0, sizeof(tmp_shark));

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(!shark[r][c].z){ continue; }

            int x = 0, y = 0;
            if(shark[r][c].d == 0 || shark[r][c].d == 2){ y = shark[r][c].s; }
            else { x = shark[r][c].s; }

            while (!(x == 0 && y == 0)) {
                
            }
        }
    }

   copy_shark();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> M;
    for(int m = 0; m<M; m++){
        cin >> r >> c >> s >> d >> z;
        z = change_dir(z);
        shark[r][c] = {s, d, z};
    }

    int king = 0;
    while (king < C) {
        king++;

        for(int i=1; i<=R; i++){
            if(!shark[i][king].z){ continue; }
            else{
                result += shark[i][king].z;
                shark[i][king] = {0, 0, 0};
                break;
            }
        }

        move_shark();
    }
    
    cout << result;
    return 0;
}
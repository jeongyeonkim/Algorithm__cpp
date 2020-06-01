// 피아의 아틀리에 ~신비한 대회의 연금술사~
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, result;
int arrINT[11][4][6][6], selected[4], tempINT[6][6];
char arrCHAR[11][4][6][6], tempCHAR[6][6];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> dINT;
vector<char> dCHAR;

void arrClear(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){ tempCHAR[i][j] = 'W'; tempINT[i][j] = 0; }
    }
}

void solve(){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int z=0; z<2; z++){
                
            }
        }
    }
}

void Alchemist(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int z=0; z<4; z++){
                
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int t=0; t<n; t++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){ cin >> arrINT[t][0][i][j]; }
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){ cin >> arrCHAR[t][0][i][j]; }
        }

        dINT.push_back(arrINT[t][0][0][0]);
        dCHAR.push_back(arrCHAR[t][0][0][0]);
        int x = 0, y = 1, d = 0;
        while (!(x == 0 && y == 0)){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4){ d = (d + 1) % 4; continue; }
            dINT.push_back(arrINT[t][0][nx][ny]);
            dCHAR.push_back(arrCHAR[t][0][nx][ny]);
            x = nx; y = ny;
        }
        
        int idx = 1;
        while (idx < 4){
            int i = idx * 4;
            int r = 0,  c = 1, dir = 0;
            arrINT[t][idx][0][0] = dINT[i];
            arrCHAR[t][idx][0][0] = dCHAR[i++];
            while (!(r == 0 && c == 0)){
                arrINT[t][idx][r][c] = dINT[i];
                arrCHAR[t][idx][r][c] = dCHAR[i++];
                if(i == 16){ i = 0; }
                int nr = r + dx[dir];
                int nc = c + dy[dir];
                if(nr < 0 || nc < 0 || nr >= 4 || nc >= 4){ dir = (dir + 1)%4; nr = r + dx[dir]; nc = c + dy[dir]; }
                r = nr; c = nc;
            }
            arrINT[t][idx][1][1] = arrINT[t][idx-1][1][2];
            arrINT[t][idx][1][2] = arrINT[t][idx-1][2][2];
            arrINT[t][idx][2][2] = arrINT[t][idx-1][2][1];
            arrINT[t][idx][1][2] = arrINT[t][idx-1][1][1];
            arrCHAR[t][idx][1][1] = arrCHAR[t][idx-1][1][2];
            arrCHAR[t][idx][1][2] = arrCHAR[t][idx-1][2][2];
            arrCHAR[t][idx][2][2] = arrCHAR[t][idx-1][2][1];
            arrCHAR[t][idx][1][2] = arrCHAR[t][idx-1][1][1];
        }
    }

    for(int i=0; i<n; i++){
        selected[0] = i;
        for(int j=0; j<n; j++){
            if(i == j){ continue; }
            selected[1] = j;
            for(int z=0; z<n; z++){
                if(i == z || j == z){ continue; }
                selected[2] = z;
                Alchemist();
            }
        }
    }

    cout << result;
    return 0;
}
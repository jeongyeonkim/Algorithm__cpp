// 알파벳
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R, C, result;
char arr[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void alpabat(int x, int y, vector<char> &vec){
    vec.push_back(arr[x][y]);
    result = max(result, (int)vec.size());

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C){ continue; }

        bool check = true;
        int k = 0;
        while(k < vec.size()){
            if(vec[k] == arr[nx][ny]){ check = false; break; }
            k++;
        }

        if(check){
            alpabat(nx, ny, vec);
            vec.pop_back();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
        }
    }
    vector<char > v;
    alpabat(0, 0, v);

    cout << result;
}
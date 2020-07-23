// 숫자판 점프
#include <iostream>
#include <map>
#include <string>
using namespace std;
int arr[6][6];
map<string, int> res;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

void numberJump(int x, int y, string str){
    if(str.length() == 6){
        if(res.find(str) == res.end()){
            res.insert(make_pair(str, 0));
        }
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5){ continue; }
        numberJump(nx, ny, str + to_string(arr[nx][ny]));
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){ cin >> arr[i][j]; }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            numberJump(i, j, to_string(arr[i][j]));
        }
    }

    cout << res.size();
    return 0;
}
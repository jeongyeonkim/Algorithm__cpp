// 격자판의 숫자 이어 붙이기
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int test_case, T;
int arr[4][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
set<int> num;


void DFS(int x, int y, int cnt, int val){
    if(cnt == 0){
        num.insert(val);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4){ continue; }
        DFS(nx, ny, cnt - 1, val+(arr[nx][ny]*pow(10,cnt-1)));
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        for(int i= 0; i<4; i++){
            for(int j=0; j<4; j++){ cin >> arr[i][j]; }
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                DFS(i, j, 6, arr[i][j]*pow(10, 6));
            }
        }

        cout << "#" << test_case << " " << num.size()<< "\n";
        num.clear();
    }

    return 0;
}
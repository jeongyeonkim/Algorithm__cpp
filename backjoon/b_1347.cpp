// 미로 만들기
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N, dir, x, y;
int minX, minY, maxX, maxY;
string str;
int arr[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(arr, -1, sizeof(arr));
    cin >> N;
    cin >> str;
    x = 50; y = 50;
    dir = 1;
    arr[x][y] = 0;
    minX = minY = maxX = maxY = 50;
    for(int i=0; i<N; i++){
        if(str[i] == 'R'){ dir = (dir + 1) % 4; }
        else if(str[i] == 'L'){ dir = (dir + 3) % 4; }
        else if(str[i] == 'F'){ // 움직일 때마다 가능한 x,y좌표의 최대 최소값 저장 -> 직사각형을 이루면서 출력하기 위해
            x += dx[dir];
            y += dy[dir];
            arr[x][y] = 0;
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
    }

    for(int i=minX; i<=maxX; i++){
        for(int j=minY; j<=maxY; j++){
            if(arr[i][j] == 0){ cout << "."; }
            else{ cout << "#"; }
        }
        cout << "\n";
    }

    return 0;
}
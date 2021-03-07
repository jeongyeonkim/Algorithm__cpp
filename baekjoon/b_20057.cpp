// 마법사 상어와 토네이도
// 2992KB 40ms
#include <iostream>
using namespace std;
int N;
int sandMap[500][500];
int result;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

// 1. dx, dy 뱡향 > 서, 남서, 남, 동남, 동, 북동, 북, 북서 순서
// 2. moveSand > 모래 이동하는 항수
// 3. 방향 2번씩 바뀔 때 마다 한 방향에서 이동할 수 있는 칸수 올려줘야 함
// 4. 한 뱡향에서 이동할 수 있는 칸 수를 채웠을 경우 cnt++
bool isRange(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

void calculat(int x, int y, int d, int mult, int val, int addvalue){
    if(isRange(x + (dx[(d+val) % 8] * mult), y + (dy[(d+val) % 8] * mult))){
        sandMap[x + (dx[(d+val) % 8] * mult)][y + (dy[(d+val) % 8] * mult)] += addvalue;
    }else{
        result += addvalue;
    }
}

void moveSand(int x, int y, int d){
    int sand = sandMap[x][y];

    // 10%
    int addvalue = (int)(sand * 0.1);
    sandMap[x][y] -= (addvalue * 2);
    calculat(x, y, d, 1, 7, addvalue);
    calculat(x, y, d, 1, 1, addvalue);
    // 7%
    addvalue = (int)(sand * 0.07);
    sandMap[x][y] -= (addvalue * 2);
    calculat(x, y, d, 1, 2, addvalue);
    calculat(x, y, d, 1, 6, addvalue);
    // 5%
    addvalue = (int)(sand * 0.05);
    sandMap[x][y] -= addvalue;
    calculat(x, y, d, 2, 0, addvalue);
    // 2%
    addvalue = (int)(sand * 0.02);
    sandMap[x][y] -= (addvalue * 2);
    calculat(x, y, d, 2, 2, addvalue);
    calculat(x, y, d, 2, 6, addvalue);
    // 1%
    addvalue = (int)(sand * 0.01);
    sandMap[x][y] -= (addvalue * 2);
    calculat(x, y, d, 1, 5, addvalue);
    calculat(x, y, d, 1, 3, addvalue);

    calculat(x, y, d, 1, 0, sandMap[x][y]);

    sandMap[x][y] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) { cin >> sandMap[i][j]; }
    }

    int x = N/2;
    int y = N/2;
    int dir = 0;
    int cnt = 0;
    int moveCnt = 1;
    int dirCnt = 0;

    while (true) {
        if(x == 0 && y == 0){ break; }
        x += dx[dir];
        y += dy[dir];
        moveSand(x, y, dir);
        dirCnt++;
        if(dirCnt == moveCnt){
            dir = (dir + 2) % 8;
            cnt++;
            if(cnt == 2){
                moveCnt++;
                cnt = 0;
            }
            dirCnt = 0;
        }
    }
    cout << result;
    return 0;
}
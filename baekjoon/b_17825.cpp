// 주사위 윷놀이
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
pair<int, int> horse[4];
int arr[10], result;
bool goal[4];
int board[5][26]={
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0, 0, 0, 0, 0},
    {10, 13, 16, 19, 25},
    {20, 22, 24, 25},
    {30, 28, 27, 26, 25},
    {25, 30, 35, 40}
};

void game(int num, int sum){
    if(num >= 10){ // 주사위 10번 넘었을 경우
        result = max(result, sum);
        return;
    }

    for(int i=0; i<4; i++){
        int tempDir = horse[i].first;
        int tempX = horse[i].second;

        if(!goal[i]){
            int ndir = horse[i].first;
            int nx = horse[i].second + arr[num];

            if(ndir == 0 && nx == 5){ ndir = 1, nx = 0; } // 방향 회전하고 나서 또 변경 되는거 있는지 확인!! else if x  -> 방향 두 번 회전일 수 있음
            if(ndir == 0 && nx == 10){ ndir = 2; nx = 0; }
            if(ndir == 0 && nx == 15){ ndir = 3; nx = 0; }
            if(ndir == 1 && nx >= 4){ ndir = 4; nx -= 4; }
            if(ndir == 2 && nx >= 3){ ndir = 4; nx -= 3; }
            if(ndir == 3 && nx >= 4){ ndir = 4; nx -= 4; }
            if(ndir == 4 && nx >= 3){ ndir = 0; nx += 17; }

            if(!board[ndir][nx]){ goal[i] = true; }
            bool check = true;
            for(int j=0; j<4; j++){
                if(i == j){ continue; }
                if(!goal[j]){
                    if(ndir == horse[j].first && nx == horse[j].second){
                        check = false;
                        break;
                    }
                }
            }

            if(check){ // 다음 자리에 말이 없을 경우 dfs 수행
                horse[i].first = ndir;
                horse[i].second = nx;
                game(num + 1, sum + board[ndir][nx]);
                goal[i] = false;
                horse[i].first = tempDir;
                horse[i].second = tempX;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<10; i++){ cin >> arr[i]; }
    pair<int, int> horse[4];
    for(int i=0; i<4; i++){
        horse[i].first = 0;
        horse[i].second = 0;
        goal[i] = false; 
    }
    game(0, 0);

    cout << result;
    return 0;
}
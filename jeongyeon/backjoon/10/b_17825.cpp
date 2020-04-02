// 주사위 윷놀이
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int arr[10], result;
bool goal[4];
int board[5][26]={
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0, 0, 0, 0, 0},
    {10, 13, 16, 19, 25},
    {20, 22, 24, 25},
    {30, 28, 27, 26, 25},
    {25, 30, 35, 40}
};

void game(int num, pair<int, int> horse[4], int sum){
    if(num >= 10){
        result = max(result, sum);
        return;
    }

    pair<int, int> temp[4];
    for(int i=0; i<4; i++){ temp[i].first = horse[i].first; temp[i].second = horse[i].second; }

    for(int i=0; i<4; i++){
        if(!goal[i]){
            int ndir = temp[i].first;
            int nx = temp[i].second + arr[num];

            if(ndir == 0 && nx == 5){ ndir = 1, nx = 0; }
            else if(ndir == 0 && nx == 10){ ndir = 2; nx = 0; }
            else if(ndir == 0 && nx == 15){ ndir = 3; nx = 0; }
            else if(ndir == 1 && nx >= 4){ ndir = 4; nx -= 4; }
            else if(ndir == 2 && nx >= 3){ ndir = 4; nx -= 3; }
            else if(ndir == 3 && nx >= 4){ ndir = 4; nx -= 4; }
            else if(ndir == 4 && nx >= 3){ ndir = 0; nx += 17; }

            if(!board[ndir][nx]){ goal[i] = true; }
            bool check = true;
            for(int j=0; j<4; j++){
                if(i == j){ continue; }
                if(!goal[j]){
                    if(ndir == temp[j].first && nx == temp[j].second){
                        check = false;
                        break;
                    }
                }
            }

            if(check){
                temp[i].first = ndir;
                temp[i].second = nx;
                game(num + 1, temp, sum + board[ndir][nx]);
                goal[i] = false;
                temp[i].first = horse[i].first;
                temp[i].second = horse[i].second;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<10; i++){ cin >> arr[i]; }
    pair<int, int> horse[4];
    for(int i=0; i<4; i++){ horse[i].first = 0; horse[i].second = 0; goal[i] = false; }
    game(0, horse, 0);

    cout << result;
    return 0;
}
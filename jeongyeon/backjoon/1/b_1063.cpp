// 킹
#include <iostream>
#include <string.h>
using namespace std;
int N, idx;
string K, S, arr[51];
pair<int, int> king, stone;
string dir[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

bool checkMap(int x, int y){
    if(x < 0 || y < 0 || x >=8 || y >=8){ return false; }
    return true;
}

void solve(){
    int nxKing = king.first + dx[idx];
    int nyking = king.second + dy[idx];

    if(!checkMap(nxKing, nyking)){ return; }

    if(nxKing == stone.first && nyking == stone.second){
        int nxStone = stone.first + dx[idx];
        int nyStone = stone.second + dy[idx];

        if(!checkMap(nxStone, nyStone)){ return; }
        stone.first = nxStone;
        stone.second = nyStone;
        king.first = nxKing;
        king.second = nyking;
    }else{
        king.first = nxKing;
        king.second = nyking;
    }
}

int main(void){
    cin >> K >> S;
    king.first = K[1] - '0';
    king.first = 8 - king.first;
    king.second = K[0] - '0' - 17;
    stone.first = S[1] - '0';
    stone.first = 8 - stone.first;
    stone.second = S[0] - '0' - 17;

    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }

    for(int i=0; i<N; i++){
        for(int j=0; j<8; j++){
            if(arr[i] == dir[j]){ idx = j; }
        }
        solve();
    }

    char kingX = king.second + '0' + 17;
    cout << kingX << 8-king.first << "\n";
    char stoneX = stone.second + '0' + 17;
    cout << stoneX << 8-stone.first << "\n";
    return 0;
}
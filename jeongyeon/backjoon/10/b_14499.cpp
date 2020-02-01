// 주사위 굴리기
#include <iostream>
#include <vector>
using namespace std;
int N, M, x, y, K;
int arr[21][21], dice[7];
vector<int> result;

bool checkDirection(int t){
    if(t == 1){
        if(y+1 < M){ ++y; return true; }
    }else if(t == 2){
        if(y-1 >= 0){ --y; return true; }
    }else if(t == 3){
        if(x-1 >= 0){ --x; return true; }
    }else{
        if(x+1 < N){ ++x; return true; }
    }

    return false;
}

void changeDice(int t){
    int temp = 0;
    switch (t){
    case 1:
        temp = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = temp;
        break;
    
    case 2:
        temp = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = temp;
        break;

    case 3:
        temp = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = temp;
        break;
    
    case 4:
        temp = dice[6];
        dice[6] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
        break;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> arr[i][j];}
    }

    for(int i=0; i<K; i++){
        int direction;
        cin >> direction;

        if(checkDirection(direction) == 1){
            changeDice(direction);
            if(arr[x][y] == 0){
                result.push_back(dice[1]);
                arr[x][y] = dice[6];
            }else{
                result.push_back(dice[1]);
                dice[6] = arr[x][y];
                arr[x][y] = 0;
            }
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}
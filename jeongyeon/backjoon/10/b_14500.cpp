// 테트로미노
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result;
int arr[501][501];
int block[19][3][2] =  {
    {{0, 1}, {0, 2}, {0, 3}}, // 일자모양
    {{1, 0}, {2, 0}, {3, 0}},
    {{0, 1}, {1, 0}, {1, 1}}, // 정사각형
    {{1, 0}, {2, 0}, {2, 1}}, // 'ㄴ'자 모양
    {{0, 1}, {0, 2}, {-1, 2}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}},
    {{1, 0}, {1, 1}, {2, 1}}, // 'z' 모양
    {{1, 0}, {1, -1}, {0, 1}},
    {{1, 0}, {0, 1}, {-1, 1}},
    {{0, -1}, {1, 0}, {1, 1}},
    {{0, 1}, {-1, 1}, {-2, 1}}, // 'ㄴ' 반대 모양
    {{0, 1}, {0, 2}, {1, 2}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{0, -1}, {1, 0}, {0, 1}}, // 'ㅗ' 모양
    {{-1, 0}, {0, 1}, {1, 0}},
    {{0, -1}, {-1, 0}, {0, 1}},
    {{-1, 0}, {0, -1}, {1, 0}}
};

void Tetromino(int x, int y){
    for(int i=0; i<19; i++){
        int sum = arr[x][y];
        bool check = true;
        for(int j=0; j<3; j++){
            int nx = x + block[i][j][0];
            int ny = y + block[i][j][1];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M){ sum +=  arr[nx][ny]; }
            else{ check = false; break; }
        }
        if(check){ result = max(result, sum); }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> arr[i][j]; }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ Tetromino(i, j); }
    }

    cout << result;
}
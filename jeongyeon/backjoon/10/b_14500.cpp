// 테트로미노
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, result;
int arr[501][501], visited[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair <int, int> > vec;

int othershape(int x, int y){
    int sum = arr[x][y];
    int res = 0;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
        sum += arr[nx][ny];
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 || ny >= 0 || nx < N || ny < M){ res = max(res, sum - arr[nx][ny]); }
        else{ res = max(res, sum); }
    }
    return res;
}


void Tetromino(int x, int y, int depth){
    if(depth > 2){
        int sum = 0;
        for(int i=0; i<vec.size(); i++){ sum += arr[vec[i].first][vec[i].second]; }
        result = max(result, sum);
        return;
    }

    result = max(result, othershape(x, y));

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
        if(!visited[nx][ny]){
            vec.push_back(make_pair(nx, ny));
            visited[nx][ny] = 1;
            Tetromino(nx, ny, depth + 1);
            visited[nx][ny] = 0;
            vec.pop_back();
        }

    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> arr[i][j]; }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            vec.push_back(make_pair(i, j));
            visited[i][j] = 1;
            Tetromino(i, j, 0);
            visited[i][j] = 0;
            vec.pop_back();
        }
    }

    cout << result;
    return 0;
}

// 모양 다 구현한 방법
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int N, M, result;
// int arr[501][501];
// int block[19][3][2] =  {
//     {{0, 1}, {0, 2}, {0, 3}}, // 일자모양
//     {{1, 0}, {2, 0}, {3, 0}},
//     {{0, 1}, {1, 0}, {1, 1}}, // 정사각형
//     {{1, 0}, {2, 0}, {2, 1}}, // 'ㄴ'자 모양
//     {{0, 1}, {0, 2}, {-1, 2}},
//     {{0, 1}, {1, 1}, {2, 1}},
//     {{0, 1}, {0, 2}, {1, 0}},
//     {{1, 0}, {1, 1}, {2, 1}}, // 'z' 모양
//     {{1, 0}, {1, -1}, {0, 1}},
//     {{1, 0}, {0, 1}, {-1, 1}},
//     {{0, -1}, {1, 0}, {1, 1}},
//     {{0, 1}, {-1, 1}, {-2, 1}}, // 'ㄴ' 반대 모양
//     {{0, 1}, {0, 2}, {1, 2}},
//     {{0, 1}, {1, 0}, {2, 0}},
//     {{1, 0}, {1, 1}, {1, 2}},
//     {{0, -1}, {1, 0}, {0, 1}}, // 'ㅗ' 모양
//     {{-1, 0}, {0, 1}, {1, 0}},
//     {{0, -1}, {-1, 0}, {0, 1}},
//     {{-1, 0}, {0, -1}, {1, 0}}
// };

// void Tetromino(int x, int y){
//     for(int i=0; i<19; i++){
//         int sum = arr[x][y];
//         bool check = true;
//         for(int j=0; j<3; j++){
//             int nx = x + block[i][j][0];
//             int ny = y + block[i][j][1];

//             if(nx >= 0 && ny >= 0 && nx < N && ny < M){ sum +=  arr[nx][ny]; }
//             else{ check = false; break; }
//         }
//         if(check){ result = max(result, sum); }
//     }
// }

// int main(void){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin >> N >> M;
//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){ cin >> arr[i][j]; }
//     }

//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){ Tetromino(i, j); }
//     }

//     cout << result;
// }
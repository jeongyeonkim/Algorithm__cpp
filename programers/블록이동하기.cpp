#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int xF, yF, cnt, dir, xC, yC, nx, ny, nxC, nyC;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visited[101][101][4];
int ndx[4][2] = {{-1, 0}, {1, 0}, {-1, 1}, {-1, -1}};

struct info{
    int x, y, cntT, dirB;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    queue<info> que;
    que.push({0, 0, 0, 0});
    visited[0][0][0] = 1;

    while (!que.empty()){
        xF = que.front().x; yF = que.front().y;
        cnt = que.front().cntT;
        dir = que.front().dirB;
        xC = xF + dx[dir]; yC = yF + dy[dir];
        que.pop();

        if((xF == N-1 && yF == N-1) || (xC == N-1 && yC == N-1)){ return cnt; }

        for(int i=0; i<4; i++){
            nx = xF + dx[i], ny = yF + dy[i];
            nxC = xC + dx[i], nyC = yC + dy[i];

            if(nx < 0 || nx >=N || nxC < 0 || nxC >= N || ny < 0 || ny >= N || nyC < 0 || nyC >= N){ continue; }
            if(board[nx][ny] == 1 || board[nxC][nyC] == 1 || visited[nx][ny][dir] == 1){ continue; }

            que.push({nx, ny, cnt + 1, dir});
            visited[nx][ny][dir] = 1;
        }

        for(int i=0; i<4; i++){
            nx = xF + dx[i], ny = yF + dy[i];
            nxC = xC + dx[i], nyC = yC + dy[i];

        }
    }
    
    return answer;
}



// #include <iostream>
// #include <queue>
// #include <string>
// #include <vector>
// using namespace std;
// int dx[4] = {0, 0, -1, 1};
// int dy[4] = {1, -1, 0, 0};
// int visited[101][101];

// struct info{ // dir >> l = 0, ㅡ = 1
//     int firstX, firstY, secondX, secondY, cnt, dir;
// };


// int solution(vector<vector<int>> board) {
//     int answer = 0;
//     int N = board.size();
//     queue<info> que;
//     que.push({0, 0, 0, 1, 0});
//     visited[0][0] = 1; visited[0][1] = 1;

//     while (!que.empty()){
//         int xF = que.front().firstX;
//         int yF = que.front().firstY;
//         int xC = que.front().secondX;
//         int yC = que.front().secondY;
//         int cnt = que.front().cnt;
//         int dir = que.front().dir;
//         que.pop();

//         if((xF == N-1 && yF == N-1) || (xC == N-1 && yC == N-1)){ return cnt; }

//         for(int i=0; i<4; i++){
//             int nxF = xF + dx[i], nyF = yF + dy[i];
//             int nxC = xC + dx[i], nyC = yC + dy[i];

//             if(nxF < 0 || nxF >=N || nxC < 0 || nxC >= N || nyF < 0 || nyF >= N || nyC < 0 || nyC >= N || board[nxF][nyF] == 1 || board[nxC][nyC] == 1){
//                 continue;
//             }
//             if(visited[nxF][nyF] == 1 && visited[nxC][nyC] == 1){ continue; }

//             que.push({nxF, nyF, nxC, nyC, cnt + 1, dir});
//             visited[nxF][nyF] == 1; visited[nxC][nyC] == 1;
//             if(i == 2 || i == 3){
//                 que.push({nxF, nyF, xF, yF, cnt + 1, (dir+1)%2});
//                 que.push({nxC, nyC, xC, yC, cnt + 1, (dir+1)%2});
//             }else{
//                 que.push({xF, yF, nxF, nyF, cnt + 1, (dir+1)%2});
//                 que.push({xC, yC, nxC, nyC, cnt + 1, (dir+1)%2});
//             }
//         }
//     }
    
//     return answer;
// }
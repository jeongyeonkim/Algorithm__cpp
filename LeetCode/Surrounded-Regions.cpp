// 130
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[201][201];
vector<vector<char>> arr;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


// 12ms, 10.3MB
// 1. DFS 사용
// 2. 배열의 테두리 값이 O인 곳부터 탐색 시작
// 3. 2에 해당되는 곳들은 O으로 고정 곳들
// 4. 2에 해당 되지 않는 O인 곳들은 X로 변경
void changeX(int x, int y){
    visited[x][y] = true;
    arr[x][y] = 'o';

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
        if(arr[nx][ny] == 'O' && !visited[nx][ny]){
            changeX(nx, ny);
        }
    }
}

void solve(vector<vector<char>>& board) {
    n = board.size();
    m = board[0].size();
    arr = board;
    // 가로
    for(int i=0; i<m; i++){
        if(board[0][i] == 'O' && !visited[0][i]){ changeX(0, i); }
        if(board[n-1][i] == 'O' && !visited[n-1][i]){ changeX(n-1, i); }
    }

    //세로
    for(int i=0; i<n; i++){
        if(board[i][0] == 'O' && !visited[i][0]){ changeX(i, 0); }
        if(board[i][m-1] == 'O' && !visited[i][m-1]){ changeX(i, m-1); }

    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] =='O' && arr[i][j] == 'O'){ board[i][j] = 'X'; }
        }
    }
}

// --------------------------------------------------------------------------------------------------------------------------

// 20ms 14.4MB
// 1. DFS 사용 + 방문 상태 저장
// 2. 탐색 지역마다 O 대신 region_code 저장
// 3. 탐색하다가 경계에 있는 O일 경우 region_status false로 바꿈
// 4. region_staus가 true인 지역인 경우 result에 코드 저장
// 5. 결과 저정 시 해당 지점 region_code가 result에 있을 경우에만 X로 변경하여 저장
vector<char> result;
int region_code;
bool region_status;

void findSurroundedRegion(int x, int y){
    arr[x][y] = region_code;
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= arr.size() || ny >= arr[0].size()) {    
            region_status = false;
            continue;
        }
        if(arr[nx][ny] == 'X' || visited[nx][ny]) { continue; }
        findSurroundedRegion(nx, ny);
    }
}

void solve_1(vector<vector<char>>& board) {
    arr = board;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'O' && !visited[i][j]){
                region_status = true;
                findSurroundedRegion(i, j);
                if(region_status){
                    result.push_back(region_code);
                }
                region_code++;
            }
        }
    }

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            if(board[i][j] == 'O'){
                vector<char>::iterator iter = find(result.begin(), result.end(), arr[i][j]);
                if(iter != result.end()){
                    board[i][j] = 'X';
                }
            }
        }
    }
}
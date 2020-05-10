#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int visited[27][27];
vector<vector<int>> arr;
int answer = 1e9, N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int d, int cost){
    visited[x][y] = 1;
    if(x == N-1 && y == N-1){
        answer = min(answer, cost);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
        if(visited[nx][ny] == 1 || arr[nx][ny] == 1){ continue; }

        if(i == d){
            dfs(nx, ny, i, cost + 100);
        }else if(i != (d+2)%2){
            dfs(nx, ny, i, cost + 600);
        }
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    arr = board;

    dfs(0, 0, 0, 0);
    memset(visited, 0, sizeof(visited));
    dfs(0, 0, 1, 0);

    return answer;
}

int main(){
    vector<vector <int> > a;
    for(int i=0; i<3; i++){
        vector<int> temp;
        for(int j=0; j<3; j++){temp.push_back(0);}
        a.push_back(temp);
    }
    solution(a);
}
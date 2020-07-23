// 불
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int test_case, N, M, escape_time;
int arr[1001][1001], visited[1001][1001], visited_fire[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string str;
bool flag;

struct info{
    int x, y;
};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test_case;
    while (test_case--){
        cin >> M >> N;
        escape_time = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        memset(visited_fire, 0, sizeof(visited_fire));
        flag = false;
        queue<info> que;
        queue<info> que_fire;
        for(int i=0; i<N; i++){
            cin >> str;
            for(int j=0; j<M; j++){
                if(str[j] == '#'){ arr[i][j] = 1; }
                else if(str[j] == '@'){
                    que.push({i, j});
                    visited[i][j] = 1;
                }
                else if(str[j] == '*'){
                    que_fire.push({i, j});
                    visited_fire[i][j] = 1;
                    arr[i][j] = -1;
                }
            }
        }


        while (!que.empty()){
            escape_time++;
            
            int size_fire = que_fire.size();
            while (size_fire--){
                int x = que_fire.front().x;
                int y = que_fire.front().y;
                que_fire.pop();

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited_fire[nx][ny]){ continue; }
                    if(arr[nx][ny] == 1 || arr[nx][ny] == -1){ continue; }
                    visited_fire[nx][ny] = 1;
                    arr[nx][ny] = -1;
                    que_fire.push({nx, ny});
                }
            }

            int size_que = que.size();
            while (size_que--){
                int x = que.front().x;
                int y = que.front().y;
                que.pop();

                if(x == 0 || y == 0 || x == N-1 || y == M-1){
                    flag = true;
                    break;
                }

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]){ continue; }
                    if(arr[nx][ny] == 1 || arr[nx][ny] == -1){ continue; }
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
            
            if(flag){ break; }
        }
    
        if(!flag){ cout << "IMPOSSIBLE \n"; }
        else{ cout << escape_time << "\n"; }
    }
    
}
// 미로 만들기
#include <iostream>
#include <string>
#include <queue>
#define MAX 51
using namespace std;
int n, result = 51;
char arr[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y, change_black;
};
queue<info> que;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        string str; cin >> str;
        for(int j=0; j<n; j++){
            arr[i][j] = str[j];
            visited[i][j] = MAX;
        }
    }
    que.push({0, 0, 0});
    visited[0][0] = 0;

    while (!que.empty()){
        int x = que.front().x; int y = que.front().y;
        int change_black = que.front().change_black;
        que.pop();

        if(x == n-1 && y == n-1){
            if(result > change_black){ result = change_black; }
            continue;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }
            if(visited[nx][ny] <= change_black){ continue; }
            
            if(arr[nx][ny] == '1'){
                que.push({nx, ny, change_black});
                visited[nx][ny] = change_black;
            }
            else{
                que.push({nx, ny, change_black + 1});
                visited[nx][ny] = change_black + 1;
            }
        }
    }
    

    cout << result;
    return 0;   
}
//소문난 칠공주
#include <iostream>
#include <string>
#include <map>
using namespace std;
int arr[6][6], visited[6][6];
map<string, int> girlMember;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int cntS, int cntY){
    if(cntS + cntY == 7){
        string temp = "";
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                temp += to_string(visited[i][j]);
            }
        }
        if(girlMember.find(temp) == girlMember.end()){ girlMember.insert(make_pair(temp, 1)); }
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny]){ continue; }
        if(arr[nx][ny] == 0 && cntY < 3){
            visited[nx][ny] = 1;
            dfs(nx, ny, cntS, cntY + 1);
            visited[nx][ny] = 0;
        }
        else if(arr[nx][ny] == 1){
            visited[nx][ny] = 1;
            dfs(nx, ny, cntS + 1, cntY);
            visited[nx][ny] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<5; i++){
        string str; cin >> str;
        for(int j=0; j<5; j++){
            if(str[j] == 'S'){ arr[i][j] = 1; }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i][j]){
                visited[i][j] = 1;
                dfs(i, j, 1, 0);
                visited[i][j] = 0;
            }
        }
    }
    
    cout << girlMember.size();
    return 0;
}
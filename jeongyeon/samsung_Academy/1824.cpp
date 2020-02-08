// 혁진이의 프로그램 검증
#include <iostream>
#include <string.h>
using namespace std;
int test_case, T, R, C;
int visited[21][21][4][16];
char arr[21][21];
string result = "NO";
// 좌, 우, 상, 하
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void program(int x, int y, int dir, int memorySize){
    if(arr[x][y] == '@'){
        result = "YES";
        return;
    }
    if(visited[x][y][dir][memorySize] == 1){ return; }
    visited[x][y][dir][memorySize] = 1;

    if(arr[x][y] == '<'){ dir = 0; }
    else if(arr[x][y] == '>'){ dir = 1; }
    else if(arr[x][y] == '^'){ dir = 2; }
    else if(arr[x][y] == 'v'){ dir = 3; }
    else if(arr[x][y] == '_'){
        if(memorySize == 0){ dir = 1; }
        else{ dir = 0; }
    }else if(arr[x][y] == '|'){
        if(memorySize == 0){ dir = 3; }
        else{ dir = 2; }
    }else if(arr[x][y] == '+'){
        if(memorySize == 15){ memorySize = 0; }
        else{ memorySize++; }
    }
    else if(arr[x][y] == '-'){
        if(memorySize == 0){ memorySize = 15; }
        else{ memorySize--; }
    }
    else if(arr[x][y]-'0' >= 0 && arr[x][y]-'0' <= 9){ memorySize = arr[x][y] - '0'; }

    if(arr[x][y] == '?'){
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= R){ nx = 0; }
            else if(nx < 0){ nx = R-1; }
            else if(ny >= C){ ny = 0; }
            else if(ny < 0){ ny = C-1; }
            program(nx, ny, i, memorySize);
        }
        
    }else{
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx >= R){ nx = 0; }
        else if(nx < 0){ nx = R-1; }
        else if(ny >= C){ ny = 0; }
        else if(ny < 0){ ny = C-1; }
        program(nx, ny, dir, memorySize);
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> R >> C;
        bool check = false;
        result = "NO";
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '@'){ check = true; }
            }
        }

        if(check){ program(0, 0, 1, 0);}
        cout << "#" << test_case << " " << result << "\n"; 
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
// 가스관
#include <iostream>
#include <string.h>
using namespace std;
int R, C;
char arr[26][26];
int visited[26][26];
pair<int, int> start, goal;
int dx[4] = {0, 1, 0, -1}; // 동 남 서 북
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y;
    char d;
}result;

int change_dir(char c, int dir){
    if(c == '|'){
        if(dir == 1 || dir == 3){ return dir; }
    }
    else if(c == '-'){
        if(dir == 0 || dir == 2){ return dir; }
    }
    else if(c == '+'){
        return dir;
    }
    else if(c == '1'){
        if(dir == 0 || dir == 1){ return (dir + 1) % 2; }
    }
    else if(c == '2'){
        if(dir == 0 || dir == 3){ return (dir + 3) % 6; }
    }
    else if(c == '3'){
        if(dir == 2){ return 3; }
        else if(dir == 3){ return 2; }
    }
    else if(c == '4'){
        if(dir == 1){ return 2; }
        else if(dir == 2){ return 1;}
    }
    return -1;
}

void pipe(int x, int y){
    if(arr[x][y] == '.'){

    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'M'){
                start.first = i; start.second = j;
            }
            else if(arr[i][j] == 'Z'){
                goal.first = i; goal.second = j;
            }
        }
    }

    pipe(start.first, start.second);

    cout << result.x << " " << result.y << " " << result.d;
    return 0;
}
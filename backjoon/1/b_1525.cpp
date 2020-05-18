// 퍼즐 
#include <iostream>
#include <string.h>
#include <queue>
#include <map>
using namespace std;
int X, Y, result = -1;
map<string, int> arr; // 중복 체크를 위해서 사용
struct info{
    int x, y, cnt, dir;
    string str;
};
queue<info> que;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    string input = "";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int a; cin >> a;
            if(a == 0){ X = i; Y = j; }
            input += to_string(a);
        }
    }
    que.push({X, Y, 0, -1, input});
    arr.insert(make_pair(input, 1));

    while (!que.empty()){
        string s = que.front().str;
        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().cnt;
        int dir = que.front().dir;
        que.pop();
        int temp[4][4];
        int idx = 0;
        if(s.compare("123456780") == 0){
            result = cnt;
            break;
        }
        for(int i=0; i<3; i++){ // string을 배열로 나눠서 바꾸기
            for(int j=0; j<3; j++){
                temp[i][j] = s[idx++] - '0';
            }
        }

        for(int i=0; i<4; i++){
            if(dir == (i + 2) % 4){ continue; }
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3){ continue; }
            temp[x][y] = temp[nx][ny]; // 0과 바꾸기
            temp[nx][ny] = 0;

            string ss = "";
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){ ss += to_string(temp[i][j]); }
            }
            if(arr.find(ss) == arr.end()){ // 중복이 아니라면
                arr.insert(make_pair(ss, 1));
                que.push({nx, ny, cnt + 1, i, ss});
            }
            temp[nx][ny] = temp[x][y]; // 되돌려 놓기
            temp[x][y] = 0;
        }
    }

    cout << result;
    return 0;
}
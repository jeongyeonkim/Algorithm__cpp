// 뱀
#include <iostream>
#include <queue>
using namespace std;
int N, K, L, result, dir, nx, ny, t;
int arr[101][101], changeDir[101][2];
// 동, 남, 서, 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair <int, int> > snake;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    // 사과 = 1, 뱀 몸통 = -1
    for(int i=0; i<K; i++){
        int x = 0, y = 0; cin >> x >> y;
        arr[x-1][y-1] = 1;
    }
    cin >> L;
    // D = 1, L = -1
    for(int i=0; i<L; i++){
        int x = 0; char c = 0; cin >> x >> c;
        changeDir[i][0] = x;
        if(c == 'D'){ changeDir[i][1] = 1; }
        else{ changeDir[i][1] = -1; }
    }

    snake.push(make_pair(0, 0));
    arr[0][0] = -1;
    while (true){
        nx += dx[dir];
        ny += dy[dir];
        result++;

        // 벽이나 몸통에 부딪히는 경우 게임 끝
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || arr[nx][ny] == -1){ break; }
        if(arr[nx][ny] != 1){ // 이동한 뱀 머리 자리에 사과가 없을 경우
            // 꼬리 한칸 줄이고 queue에서 빼냄
            arr[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        // 몸통 자리로 바꿈
        arr[nx][ny] = -1;
        snake.push(make_pair(nx, ny));

        // 방향 바꿔야하는 시간일 때
        if(result == changeDir[t][0]){
            if(changeDir[t][1] == 1){ dir = (dir + 1)%4; }
            else{ dir = (dir + 3)%4; }
            t++;
        }
    }
    
    cout << result;
    return 0;
}
// 통나무 옮기기
#include <iostream>
#include <queue>
using namespace std;
int N, result, goalX, goalY, goalD; // D -> - = 0, | = 1
int arr[51][51], visitied[51][51][2];
vector<pair <int, int> > input, output;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{ // 세 점을 저장 x, 중심 점만 저장하고, 방향 값을 들고 다님
    int x, y, dir, cnt;
};
queue<info> que;

bool unbound(int x, int y, int d){
    if(x < 0 || y < 0 || x >= N || y >= N || arr[x][y] == 1){ return true; }
    for(int i=d; i<4; i+=2){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >=N || arr[nx][ny] == 1){ return true; }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char a; cin >> a;
            if(a == '1'){ arr[i][j] = 1; }
            else if(a == 'B'){ input.push_back(make_pair(i, j)); }
            else if(a == 'E'){ output.push_back(make_pair(i, j)); }
        }
    }
    goalX = output[1].first; goalY = output[1].second; // 도착 점
    if(output[0].first == output[1].first - 1){ goalD = 1; } // 도착 점 방향 
    int d = 0;
    if(input[0].first == input[1].first - 1){ d = 1; }
    visitied[input[1].first][input[1].second][d] = 1;
    que.push({input[1].first, input[1].second, d, 0});

    while (!que.empty()){
        int x = que.front().x; int y = que.front().y;
        int dir = que.front().dir; int cnt = que.front().cnt;
        que.pop();

        if(x == goalX && y == goalY && dir == goalD){ // 목표 점에 도착하고, 방향도 같을 때
            result = cnt;
            break;
        }

        bool check = true;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
     
            if(unbound(nx, ny, dir)){ // 이동이 불가능 한 경우
                if((dir && (i == 0 || i == 2)) || (!dir && (i == 1 || i == 3))){ check = false; } // dir = 0 일 경우는 상하, dir = 1일 경우는 좌우를 못갈 경우 회전도 안됨.
                continue;
            }

            if(visitied[nx][ny][dir] == 0){ // 해당 좌표 같은 방향으로 방문한 적이 없을 경우
                visitied[nx][ny][dir] = 1;
                que.push({nx, ny, dir, cnt + 1});
            }
        }

        if(check && !visitied[x][y][(dir + 1) % 2]){ // 회전
            visitied[x][y][(dir + 1) % 2] = 1;
            que.push({x, y, (dir + 1) % 2, cnt + 1});
        }
    }

    cout << result;
    return 0;
}
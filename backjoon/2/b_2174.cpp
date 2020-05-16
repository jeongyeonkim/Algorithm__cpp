// 로봇 시뮬레이션
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int A, B, N, M;
int arr[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y, d;
};

vector<info> lobot;

int changeDir(int d, char ch){
    if(ch == 'L'){ return (d + 3) % 4; }
    else{ return (d + 1) % 4; }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> A >> B >> N >> M;
    int a, b; char c;
    lobot.push_back({0, 0, 0});
    for(int i=1; i<=N; i++){
        int d;
        cin >> a >> b >> c;
        arr[B-b][a-1] = i;
        if(c == 'N'){ d = 3; }
        else if(c == 'W'){ d = 2; }
        else if(c == 'E'){ d = 0; }
        else{ d = 1; }
        lobot.push_back({B-b, a-1, d});
    }

    while (M--){
        cin >> a >> c >> b;
        if(c == 'F'){
            for(int i=0; i<b; i++){
                int nx = lobot[a].x + dx[lobot[a].d];
                int ny = lobot[a].y + dy[lobot[a].d];

                if(nx < 0 || ny < 0 || nx >= B || ny >= A){ // 벽에 충돌했을 때
                    cout << "Robot " << a << " crashes into the wall"; return 0;
                }

                if(arr[nx][ny] != 0){ // 다른 로봇이랑 충돌했을 때
                    cout << "Robot " << a << " crashes into robot " << arr[nx][ny]; return 0;
                }

                arr[lobot[a].x][lobot[a].y] = 0;
                arr[nx][ny] = a;
                lobot[a].x = nx; lobot[a].y = ny;
            }
        }
        else{ for(int i=0; i<b; i++){ lobot[a].d = changeDir(lobot[a].d, c); } }
    }

    cout << "OK";
    return 0;
}
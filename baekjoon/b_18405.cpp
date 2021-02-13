// 경쟁적 전염
// 1. dfs
// 2. 우선순위 큐 사용해서 바이러스 번호가 작은 것들 부터 퍼트리기
// 3. S초가 다 가기 전에 바이러스 전체 맵에 차거나, X Y에 바이러스가 퍼졌을 경우 break
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K, S, X, Y, cnt;
int arr[201][201];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int s, x, y;
};
bool operator<(info a, info b) { return a.s > b.s; } 
priority_queue<info> que;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                que.push({arr[i][j], i, j});
                cnt++;
            }
        }
    }
    cin >> S >> X >> Y;

    while (S--){
        if(cnt > N*N || que.empty()){ break; }
        priority_queue<info> tmpQue = que;

        while (!que.empty()){
            int s = que.top().s;
            int x = que.top().x;
            int y = que.top().y;
            que.pop();
            
            if(x == X && y == Y){
                cnt = N*N + 1;
                break;
            }
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx <= 0 || ny <= 0 || nx > N || ny > N || arr[nx][ny]){ continue; }
                arr[nx][ny] = s;
                tmpQue.push({s, nx, ny});
            }
        }
        
        que = tmpQue;
    }

    cout << arr[X][Y];
    return 0;
}
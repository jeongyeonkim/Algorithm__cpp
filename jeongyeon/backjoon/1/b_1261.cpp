// 알고스팟

// BFS + 다익스트라 풀이
// 빈방 갈때는 덱의 앞에 넣고, 벽 부실때는 덱의 뒤에
// 빈 방으로 이동하면 가중치가 0, 벽으로 이동하면 가중치가 1인 것

#include <iostream>
#include <deque>
using namespace std;
int N, M, result = 10001;
int arr[101][101], dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair <int, int> > deq;

int main(void){
    cin >> M >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){ scanf("%1d", &arr[i][j]); }
    }

    deq.push_back(make_pair(1, 1));
    arr[1][1] = -1;

    while (!deq.empty()){
        int x = deq.back().first;
        int y = deq.back().second;
        deq.pop_back();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || ny <= 0 || nx > N || ny > M){ continue; }
            if(arr[nx][ny] == -1){ continue; }
            if(!arr[nx][ny]){
                deq.push_back(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y];
            }else{
                deq.push_front(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
            arr[nx][ny] = -1;
        }
    }
    
    cout << dist[N][M];
    return 0;
}

// DFS 풀이 -> 시간초과
// #include <iostream>
// using namespace std;
// int N, M, result = 10001;
// int arr[101][101], visited[101][101];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

// void algospot(int x, int y, int num){
//     if(x == N && y == M){
//         result = min(result, num);
//         return;
//     }

//     for(int i=0; i<4; i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if(nx <= 0 || ny <= 0 || nx > N || ny > M){ continue; }
//         if(!visited[nx][ny]){
//             visited[nx][ny] = 1;
//             if(arr[nx][ny]){ algospot(nx, ny, num + 1); }
//             else{ algospot(nx, ny, num); }
//             visited[nx][ny] = 0;
//         }
//     }

// }

// int main(void){
//     cin >> M >> N;
//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=M; j++){ scanf("%1d", &arr[i][j]); }
//     }
//     visited[1][1] = 1;
//     algospot(1, 1, 0);

//     cout << result;
//     return 0;
// }
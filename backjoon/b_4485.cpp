// 녹색 옷 입은 애가 젤다지?
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 126
#define INF 1e9
using namespace std;
int N, T;
int arr[MAX][MAX], dist[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct greenZ{
    int x, y, w;
};

struct compare{ // 
    bool operator() (greenZ p1, greenZ p2){
        if (p1.w > p2.w){ return true; }
        else{ return false; }
    }
};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true){
        T++;
        cin >> N;
        if(N == 0){ break; }
        for(int i=0; i<N; i++){
            for(int j=0; j<N;  j++){ cin >> arr[i][j]; }
        }

        priority_queue<greenZ, vector<greenZ>, compare> pq;
        pq.push({0, 0, 0});
        fill(&dist[0][0], &dist[N][0], INF);
        dist[0][0] = 0;

        while (!pq.empty()){
            int x = pq.top().x;
            int y = pq.top().y;
            int z = pq.top().w;
            pq.pop();

            if(dist[x][y] < z){ continue; }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
                if(dist[nx][ny] > z + arr[nx][ny]){
                    dist[nx][ny] = z + arr[nx][ny];
                    pq.push({nx, ny, dist[nx][ny]});
                }
            }
        }

        cout << "Problem " << T << ": " << dist[N-1][N-1] + arr[0][0] << "\n";
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}


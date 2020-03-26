// 상범빌딩
// BFS + 다익스트라 사용
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int L, R, C,  startX, startY, startZ, endX, endY, endZ;
int arr[31][31][31], visited[31][31][31];
int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};

struct building{
    int z, x, y;
};

int main(void){
    while (true){
        cin >> L >> R >> C;
        if(!L && !R && !C){ break; }
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        startX = startY = startZ = endX = endY = endZ = 0;
        for(int k=1; k<=L; k++){
            for(int i=1; i<=R; i++){
                for(int j=1; j<=C; j++){
                    char ch; scanf("%1s", &ch);
                    if(ch == '#'){ arr[k][i][j] = -1; }
                    else if(ch == 'S'){ startZ = k; startX = i; startY = j; }
                    else if(ch == 'E'){ endZ = k; endX = i; endY = j; }
                }
            }
        }
        queue<building> que;
        que.push({startZ, startX, startY});

        while (!que.empty()){
            int Z = que.front().z;
            int X = que.front().x;
            int Y = que.front().y;
            que.pop();

            if(X == endX && Y == endY && Z == endZ){ break; }

            for(int i=0; i<6; i++){
                int nextZ = Z + dz[i];
                int nextX = X + dx[i];
                int nextY = Y + dy[i];

                if(nextZ <= 0 || nextZ > L || nextX <= 0 || nextX > R || nextY <= 0 || nextY > C){ continue; }
                if(arr[nextZ][nextX][nextY] == 0 && !visited[nextZ][nextX][nextY]){
                    visited[nextZ][nextX][nextY] = visited[Z][X][Y] + 1;
                    que.push({nextZ, nextX, nextY});
                }
            }
        }
        
        if(visited[endZ][endX][endY] <= 0){ cout << "Trapped!\n"; }
        else{ cout << "Escaped in " << visited[endZ][endX][endY] << " minute(s).\n" ; }
    }
    return 0;
}
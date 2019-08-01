#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int input[101][101];
int visit[101][101];
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
int N, M, cnt, ni, nj;
queue<pair<int, int>> que;

void BFS(){
    que.push(make_pair(0,0));
    while(!que.empty()){
        cnt++;
        int queSize=que.size();
        while(queSize--){
            ni = que.front().first;
            nj = que.front().second;
            que.pop();
            if(ni == N-1 && nj == M-1)
                break;
            for(int i=0; i<4; i++){
                int nx = ni + dx[i];
                int ny = nj + dy[i];
                if(nx >=0 && nx < N && ny >= 0 && ny < M){
                    if(input[nx][ny] == 1){
                        input[nx][ny] = 0;
                        que.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if(ni == N-1 && nj == M-1)
            break;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            scanf("%1d", &input[i][j]);
    }
    BFS();
    printf("%d", cnt);
}
#include <iostream>
#include <queue>
#include <utility>
using namespace std; 
int N, M, cnt=-1;
int visit[1001][1001][2];
int input[1001][1001];
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
queue<pair<pair<int, int>, int>> que;

int BFS(){
    que.push({{0, 0},1});
    visit[0][0][1] = 1;
    
    while(!que.empty()){
        int x=que.front().first.first;
        int y=que.front().first.second;
        int b=que.front().second;
        que.pop();
        
        if(x==N-1 && y==M-1){
            cnt = visit[x][y][b];
            break;
        }
            
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(input[nx][ny]==0 && visit[nx][ny][b]==0){
                    visit[nx][ny][b] = visit[x][y][b]+1;
                    que.push({{nx, ny}, b});
                }else if(input[nx][ny]==1 && b ==1){
                    visit[nx][ny][0] = visit[x][y][b]+1;
                    que.push({{nx, ny}, b-1});
                }
            }
        }
    }
    return cnt;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            scanf("%1d", &input[i][j]);
    }
    printf("%d", BFS());
    return 0;
}
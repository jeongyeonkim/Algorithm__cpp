#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int input[1001][1001];
int visit[1001][1001];
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
int M,N,cnt;
queue<pair<int, int>> que;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> M >> N;
    bool check=true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> input[i][j];
            if(input[i][j] == 0)
                check = false;
            else if(input[i][j] == 1){
                que.push(make_pair(i,j));
                visit[i][j]++;
            }
        }
    }          
    // 초기에 모두 익은 토마토일 경우.
    if(check == true){
        cout << 0;
        return 0;
    }
    while(true){
        //토마토가 익은 위치의 인접한 부분에서 아직 익지 않은 토마토가 있을 때
        queue<pair<int,int>> q2;
        while(!que.empty()){
            int y=que.front().first;
            int x=que.front().second;
            que.pop();
            
            for(int dir=0;dir<4;dir++){
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                
                if(ny<0 || ny>=N || nx<0 || nx>=M)
                    continue;
                
                if(visit[ny][nx] || input[ny][nx]!=0)
                    continue;
                
                visit[ny][nx]++;
                input[ny][nx]=1;
                q2.push(make_pair(ny,nx));
            }
        }
        
        que=q2;
        if(que.empty()) //더이상 확인할 토마토 없는 경우
            break;
        cnt++;
    }
    // 안익은 토마토가 있을 경우
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(input[i][j]==0){
                cout << "-1";
                return 0;
            }
        }
    }
    
    cout << cnt;
    return 0;
}

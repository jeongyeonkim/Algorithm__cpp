#include <iostream>
#include <queue>
using namespace std;
int input[101][101];
int bfsVisit[101];
queue<int> que;
int N, M, result=-1;

void BFS(){
    while(!que.empty()){
        int k = que.front();
        result++;
        que.pop();
        for(int i=1; i<=N; i++){
            if(input[k][i]==1 && bfsVisit[i]==0){
                bfsVisit[i]=1;
                que.push(i);
            }
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a=0, b=0; cin >> a >> b;
        input[a][b]=1;
        input[b][a]=1;
    }
    bfsVisit[1]=1;
    que.push(1);
    BFS();
    return 0;
}
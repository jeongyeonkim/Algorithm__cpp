#include <iostream>
#include <queue>
using namespace std;
int input[1001][1001];
int dfsVisit[1001], bfsVisit[1001];
queue<int> que;
int N, M, V;

void DFS(int start){
    dfsVisit[start] =1;
    cout << start << " ";

    for(int i=1; i<=N; i++){
        if(input[start][i]==1 && dfsVisit[i]==0)
            DFS(i);
    }
}

void BFS(int start){
    bfsVisit[start]=1;
    que.push(start);

    while(!que.empty()){
        int k = que.front();
        cout << k << " ";
        que.pop();
        for(int i=1; i<=N; i++){
            if(input[k][i]==1 && bfsVisit[i]==0){
                bfsVisit[i]=1;
                que.push(i);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> V;
    for(int i=0; i<M; i++){
        int a=0, b=0; cin >> a >> b;
        input[a][b]=1;
        input[b][a]=1;
    }
    DFS(V);
    cout << "\n";
    BFS(V);
    return 0;
}
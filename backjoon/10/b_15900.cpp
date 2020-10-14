// 나무 탈출
// 1. 마지막 노드에서 노드 1까지 거리 합이 짝수면 짐
//          >> 리프 노드가 아닌 노드들은 한 노드에 여려개의 말이 놓일 수 있다는 조건이 있기 때문에 배제
// 2. 루트 노드까지의 거리 >> 다익스트라
// 3. 마지막 노드 >> 부모 노드가 1개인 것들 >> edge[k].size() == 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, u, v, result;
int node[500001];
vector<int> edge[500001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N-1; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    queue<int> que;
    que.push(1);

    while (!que.empty()){
        int k = que.front();
        que.pop();

        for(int i=0; i<edge[k].size(); i++){
            if(node[edge[k][i]] == 0 && edge[k][i] != 1){
                node[edge[k][i]] = node[k] + 1;
                que.push(edge[k][i]);
            }
        }
    }

    for(int i=2; i<=N; i++){
        if(edge[i].size() == 1){ result += node[i]; }
    }

    if((result % 2) == 0){ cout << "No"; }
    else{ cout << "Yes"; }
    return 0;
}
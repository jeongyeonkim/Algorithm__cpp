// 친구비
// union-find 사용
#include <iostream>
#include <string.h>
using namespace std;
int N, M, k, costSum;
int nodeCost[10001], node[10001];

int find(int u){
    if(node[u] == -1){ return u; }
    return node[u] = find(node[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v){ return; }
    if(nodeCost[u] > nodeCost[v]){ node[u] = v; } // 현재 노드의 cost가 더 클 경우 작은애로 바꿔줌
    else{ node[v] = u; }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M >> k;
    for(int i=1; i<=N; i++){ cin >> nodeCost[i]; }
    memset(node, -1, sizeof(node));
    int u, v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        merge(u, v);
    }

    for(int i=1; i<=N; i++){
        if(node[i] == -1){ costSum += nodeCost[i]; }
    }
    if(costSum > k){ cout << "Oh no"; }
    else{ cout << costSum; }
    return 0;
}
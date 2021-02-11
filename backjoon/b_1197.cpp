// 최소 스패닝 트리

/* 크루스칼 -> union find 사용
  가중치가 가장 작은 간선부터 시작하여 사이클이 생기지 않는 가중치가 그다음으로 작은 간선을
  추가 시키며 MST를 완성 하는 알고리즘 ElogE의 시간복잡도를 가진다.
  E의 수가 작다면 크루스칼 E의 수가 많다면 프림을 사용하는 것이 효율적임이 자명하다. 
*/
#include <iostream>
#include <algorithm>
#define E_m 100001
#define V_m 10001
using namespace std;
long long result;
struct Edge{ int u, v, w; } edge[E_m];
int node[V_m];
int V, E, a, b, c;

bool cmp(const Edge &a, const Edge &b){ return a.w < b.w; }

int find(int u){
    if(u == node[u]){ return u; }
    return node[u] = find(node[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v){ return; }
    if(u > v){ swap(u, v); }
    node[u] = v;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge+1, edge+1+E, cmp);

    for(int i=1; i<=V; i++){ node[i] = i; }
    for(int i=1; i<=E; i++){
        if(find(edge[i].u) != find(edge[i].v)){
            merge(edge[i].u, edge[i].v);
            result += edge[i].w;
        }
    }

    cout << result;
    return 0;
}
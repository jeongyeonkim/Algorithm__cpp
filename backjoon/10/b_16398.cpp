// 행성 연결
// 크루스칼 알고리즘
#include <iostream>
#include <algorithm>
#define V_MAX 1001
#define E_MAX 1000001
using namespace std;
int N;
int node[V_MAX];
long long result;
struct Edge{int u, v, w; } edge[E_MAX];

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
    cin >> N;
    int idx = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a; cin >> a;
            if(j > i){ edge[idx].u = i; edge[idx].v = j; edge[idx++].w = a; }
        }
    }
    sort(edge+1, edge+idx, cmp);

    for(int i=1; i<=N; i++){ node[i] = i; }
    for(int i=1; i<idx; i++){
        if(find(edge[i].u) != find(edge[i].v)){
            merge(edge[i].u, edge[i].v);
            result += edge[i].w;
        }
    }
    
    cout << result;
    return 0;
}
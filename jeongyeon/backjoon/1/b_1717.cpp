// 집합의 표현
// Disjoint Set
#include <iostream>
#include <algorithm>
#define Max 1000001
using namespace std;
int N, M, a, b, c;
int node[Max];

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
    cin >> N >> M;
    int idx = 0;
    for(int i=1; i<=N; i++){ node[i]  = i; }
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        if(a == 0){ merge(b, c); }
        else{
            if(find(b) == find(c)){ cout << "YES\n"; }
            else{ cout << "NO\n"; }
        }
    }
}
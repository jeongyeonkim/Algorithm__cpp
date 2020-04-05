// 네트워크 연결
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int N, M, U, V, W, cnt;
struct node{ int u, v, w; } edge[MAX];
int Node[1001];
long long result;

bool cmp(const node &a, const node &b){ return a.w < b.w; }

int find(int u){
    if(u == Node[u]){ return u; }
    return Node[u] = find(Node[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){ return; }
    if(u > v){ swap(u, v); }
    Node[u] = v;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> U >> V >> W;
        edge[i].u = U;
        edge[i].v = V;
        edge[i].w = W;
    }
    sort(edge+1, edge+1+M, cmp);

    for(int i=1; i<=N; i++){ Node[i] = i; }
    for(int i=1; i<=M; i++){
        U = find(edge[i].u);
        V = find(edge[i].v);
        if(U == V){ continue; }
        merge(U, V);
        result += edge[i].w;
        if(++cnt == N-1){ break; }
    }

    cout << result;
    return 0;
}
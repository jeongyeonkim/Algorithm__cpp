// 도시 분할 계획
// 1. MST
// 2. 두 개의 분리된 마을 >> MST로 결과 값 구한 후 가장 값이 큰 간선 제거하면 두 개의 마을 생성됨
// 3. 크루스칼 알고리즘 >> 유니온 파인드 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, maxW;
long long result;
struct Info{
    int u, v, w;
};
Info edge[1000001];
int node[100001];

bool cmp(const Info &a, const Info &b){ return a.w < b.w; }

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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){ node[i] = i; }
    for(int i=1; i<=M; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge+1, edge+1+M, cmp);

    for(int i=1; i<=M; i++){
        if(find(edge[i].u) != find(edge[i].v)){
            merge(find(edge[i].u), find(edge[i].v));
            result += edge[i].w;
            maxW = max(maxW, edge[i].w);
        }
    }

    cout << result - maxW;
    return 0;
}
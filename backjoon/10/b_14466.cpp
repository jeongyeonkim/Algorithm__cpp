// 소가 길을 건너간 이유 6
// 유니온 파인드 사용.
// 다리가 없으면 병합 해주기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, R, result;
int dx[4] = {0, 1, 0, -1}; // 동, 남, 서, 북
int dy[4] = {1, 0, -1, 0};
int node[10001], edge[101][101][5];

struct info{
    int x, y;
};
vector<info> cow;

int find(int u){
    if(u == node[u]){ return u; }
    return node[u] = find(node[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v){ return; }
    node[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> R;
    for(int i=1; i<=N*N; i++){ node[i] = i; }
    for(int i=0; i<R; i++){
        int u1, v1, u2, v2;
        cin >> u1 >> v1 >> u2 >> v2;
        u1--; v1--; u2--; v2--;
        if(v1 == v2){
            if(u1 > u2){ swap(u1, u2); }
            edge[u1][v1][1] = edge[u2][v2][3] = 1;
        }else if(u1 == u2) {
            if(v1 > v2){ swap(v1, v2); }
            edge[u1][v1][0] = edge[u2][v2][2] = 1;
        }
    }
    for(int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cow.push_back({a, b});
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int d=0; d<4; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(ni >= 0 && ni < N && nj >= 0 && nj < N && !edge[i][j][d]){
                    merge(find(i * N + j), find(ni * N + nj));
                }
            }
        }
    }

    for(int i=0; i<K-1; i++){
        for(int j=i+1; j<K; j++){
            if(find(cow[i].x * N + cow[i].y) != find(cow[j].x * N + cow[j].y)){
                result++;
            }
        }
    }
    
    cout << result;
    return 0;
}
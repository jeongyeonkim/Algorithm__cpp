// 파티
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
int N, M, X, u, v, w, maxTime;
vector<pair <int, int> > arr[MAX];
int dist[MAX], result[MAX];

// 다익스트라
int party(int start, int goal){
    fill(dist, dist+MAX, 1e9);
    int res = 1e9;
    priority_queue<pair <int, int> > que;
    que.push(make_pair(0, start));
    dist[start] = 0;

    while (!que.empty()){
        int node = que.top().second;
        que.pop();
        // 목적지 까지의 최소 거리
        if(node == goal){ res = min(res, dist[node]); }

        for(int j=0; j<arr[node].size(); j++){
            int nextNode = arr[node][j].first;
            int nextCost = arr[node][j].second;

            if(dist[nextNode] > dist[node] + nextCost){
                dist[nextNode] = dist[node] + nextCost;
                que.push(make_pair((-1)*dist[nextNode], nextNode));
            }
        }
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }

    for(int i=1; i<=N; i++){
        if(i == X){ continue; }
        result[i] = party(i, X); // 행사장 갈때
        result[i] += party(X, i); // 마을 돌아갈 때
    }

    // 가장 오래 걸리는 소요시간 찾기
    for(int i=1; i<=N; i++){ maxTime = max(maxTime, result[i]); }
    cout << maxTime;
    return 0;
}
// 최소비용 구하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 20001
using namespace std;
int N, M, result = 1e9, u, v, w, start, goal;
vector<pair <int, int> > arr[MAX];
int dist[MAX];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }
    cin >> start >> goal;
    fill(dist, dist+MAX, 1e9);
    priority_queue<pair <int, int> > que;
    que.push(make_pair(0, start));
    // dist = 해당 노드까지 최단 거리 값 저장 배열
    dist[start] = 0;

    while (!que.empty()){
        int node = que.top().second;
        int Cost = (-1)*que.top().first;
        que.pop();

        if(node == goal){ result = min(result, dist[node]); }

        for(int i=0; i<arr[node].size(); i++){
            int nextNode = arr[node][i].first;
            int nextCost = arr[node][i].second;

            if(dist[nextNode] > dist[node] + nextCost){
                dist[nextNode] = dist[node] + nextCost;
                que.push(make_pair((-1)*dist[nextNode], nextNode));
            }
        }
    }

    cout << result;
    return 0;
}
// 최단경로
// 다익스트라 알고리즘 기본 문제
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 1e9
using namespace std;
int V, E, start, u, v, w;
vector<pair <int, int> > arr[MAX];
int dist[MAX];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> V >> E;
    cin >> start;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }
    fill(dist, dist+MAX, INF);
    priority_queue<pair <int, int> > que;
    que.push(make_pair(0, start));
    dist[start] = 0;

    while (!que.empty()){
        // 우선순위 큐는 내림차순이라 오름차순으로 넣기 위해서 -1 곱함
        int cost = (-1)*que.top().first;
        int node = que.top().second;
        que.pop();

        for(int i=0; i<arr[node].size(); i++){
            int next = arr[node][i].first;
            int nextC = arr[node][i].second;

            if(dist[next] > dist[node] + nextC){
                dist[next] = dist[node] + nextC;
                que.push(make_pair((-1)*dist[next], next));
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(dist[i] == INF){ cout << "INF" << "\n"; }
        else{ cout << dist[i] << "\n"; }
    }
}
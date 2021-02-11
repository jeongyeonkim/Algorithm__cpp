// 숨바꼭질
// 각 간선에 가중치 1로 주고 다익스트라 사용
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define MAX 20001
#define INF 1e9
using namespace std;
int N, M, x, y, z;
vector<pair <int, int> > arr[MAX];
int dist[MAX];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a = 0, b =  0; cin >> a >> b;
        arr[a].push_back(make_pair(b, 1));
        arr[b].push_back(make_pair(a, 1));
    }
    fill(dist, dist+MAX, INF);
    priority_queue<pair <int, int> > que;
    dist[1] = 0;
    que.push(make_pair(0, 1));

    while (!que.empty()){
        int cost = (-1)*que.top().first;
        int node = que.top().second;
        que.pop();

        for(int i=0; i<arr[node].size(); i++){
            int nextCost = arr[node][i].second;
            int nextNode = arr[node][i].first;

            if(dist[nextNode] > dist[node] + nextCost){
                dist[nextNode] = dist[node] + nextCost;
                que.push(make_pair((-1)*dist[nextNode], nextNode));
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(dist[i] != INF){
            if(y < dist[i]){
                y = dist[i];
                z = 1;
                x = i;
            }else if(y == dist[i]){ z++; }
        }
    }

    cout << x << " " << y << " " << z;
    return 0;
}
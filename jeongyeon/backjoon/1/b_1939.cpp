// 중량제한
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, a, b, c, result, start, goal;
vector<pair <int, int> > arr[10001];
int node[10001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }
    cin >> start >> goal;

    queue<int> que;
    node[start] = 0;

    for(int i=0; i<arr[start].size(); i++){
        que.push(arr[start][i].first);
        node[arr[start][i].first] = arr[start][i].second;
    }

    while (!que.empty()){
        int x = que.front();
        que.pop();

        if(x == goal){
            result = max(result, node[x]);
            que.pop();
        }

        for(int i=0; i<arr[x].size(); i++){
            int nx = arr[x][i].first;
            int nw = arr[x][i].second;
            
            if(nx == start){ continue; }
            if(node[x] < nw){ node[nx] = node[x]; }
            else{ node[nx] = nw; }
            que.push(nx);
        }
    }
    
    cout << result;
    return 0;
}
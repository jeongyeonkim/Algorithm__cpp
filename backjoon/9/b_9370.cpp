// 미확인 도착지
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int T, n, m, t, s, g, h, x;
vector<pair <int, int>> arr[2001];
vector<int> result, dijS, dijH, dijG;

vector<int> dij(int start){
    vector<int> dist(n+1, INF);
    priority_queue<pair <int, int> > que;
    que.push(make_pair(0, start));
    dist[start] = 0;

    while (!que.empty()){
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
    return dist;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for(int i=1; i<=n; i++){ arr[i].clear(); }
        result.clear();
        dijS.clear(); dijH.clear(); dijG.clear();

        for(int i=0; i<m; i++){
            int a, b, c; cin >> a >> b >> c;
            arr[a].push_back(make_pair(b, c));
            arr[b].push_back(make_pair(a, c));
        }
        for(int i=0; i<t; i++){
            int k; cin >> k;
            result.push_back(k);
        }
        sort(result.begin(), result.end());
        dijS = dij(s);
        dijH = dij(h);
        dijG = dij(g);

        vector<int> res;
        for(int i=1; i<=n; i++){
            if (dijS[i] == dijS[g] + dijG[h] + dijH[i] || dijS[i] == dijS[h] + dijH[g] + dijG[i]) { res.push_back(i); }
        }
        for(int i=0; i<result.size(); i++){
            for(int j=0; j<res.size(); j++){
                if(result[i] == res[j]){ cout << result[i] << " "; }
            }
        }
        cout << "\n";
    }
}
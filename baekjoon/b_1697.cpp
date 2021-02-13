#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int visit[100001];

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int N, K, cnt;   cin >> N >> K;
    queue<pair<int, int>> que;
    
    que.push(make_pair(N,0));
    visit[N]=1;
    while(!que.empty()){
        int node = que.front().first;
        int nodeCNT = que.front().second;
        que.pop();
        
        if(node == K){
            cout << nodeCNT;
            return 0;
        }
        if(node >= 0 && node*2 <= 100000 && visit[node*2] == 0){
            que.push(make_pair(node*2, nodeCNT+1));
            visit[node*2]=1;
        }
        if(node+1 >= 0 && node+1 <= 100000 && visit[node+1] == 0){
            que.push(make_pair(node+1, nodeCNT+1));
            visit[node+1]=1;
        }
        if(node-1 >= 0 && node-1 <= 100000 && visit[node-1] == 0){
            que.push(make_pair(node-1, nodeCNT+1));
            visit[node-1]=1;
        }
    }
}

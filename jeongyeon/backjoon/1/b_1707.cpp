// 이분 그래프
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int K, V, E;
int visited[20001][20001];
int result;
vector<int> arr[20001];

void binaryGraph(int x){
    if(visited[x] > arr[x].size()){ result = 1; return; }
    visited[x]++;
    
    for(int i=0; i<arr[x].size(); i++){
        binaryGraph(arr[x][i]);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> K;
    while (K--){
        cin >> V >> E;
        int a = 0, b = 0;
        for(int i=0; i<E; i++){
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for(int i=1; i<=V; i++){
            if(visited[i] == 0 && result == 0){ binaryGraph(i); }
        }

        if(result == 0){ cout << "YES \n"; }
        else{ cout << "NO \n"; }
        for(int i=0; i<=V; i++){ arr[i].clear(); }
        memset(visited, 0, sizeof(visited));
    }
    
}
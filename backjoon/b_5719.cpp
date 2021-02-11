// 거의 최단 경로
// 다익스트라 -> BFS -> 다익스트라
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX 501
using namespace std;
int N, M, S, D, U, V, P;
vector<pair <int, int> > arr[MAX], edge;
int dist[MAX]; // 최소 거리 저장
int distParent[MAX]; // 최소거리 부모 모드 저장
bool check = false;

void removeEdge(){
    // 중복된 간선은 빼려고 정렬
    sort(edge.begin(), edge.end());
    int beforeP = -1, beforeC = -1;

    for(int i=0; i<edge.size(); i++){
        int idx = 0;
        int parent = edge[i].first;
        int child = edge[i].second;

        // 중복된 간선일 경우 continue
        if(beforeP == parent && beforeC == child){ continue; }
        else{ beforeP = parent; beforeC = child; }
        
        // 삭제할 값 인덱스 구하기
        for(int j=0; j<arr[parent].size(); j++){
            if(arr[parent][j].first == child){
                idx = j;
                break;
            }
        }
        // 자식 노드 삭제
        arr[parent].erase(arr[parent].begin() + idx);
    }
}

void findPath(){
    fill(dist, dist+MAX, 1e9);
    priority_queue<pair <int, int> > que;
    que.push(make_pair(0, S));
    dist[S]= 0;

    while (!que.empty()){
        int cost = (-1)*que.top().first;
        int node = que.top().second;
        que.pop();
        
        if(arr[node].empty()){ continue; }
        for(int i=0; i<arr[node].size(); i++){
            int nextNode = arr[node][i].first;
            int nextCost = arr[node][i].second;

            if(dist[nextNode] >= dist[node] + nextCost){
                distParent[nextNode] = node;
                que.push(make_pair((-1)*dist[nextNode], nextNode));

                if(nextNode == D && !check){ // 최단 거리 구할때 간선 저장
                    // 최단 거리가 같은게 아니면 이미 저장된 edge 비우기
                    if(dist[nextNode] > dist[node] + nextCost){ edge.clear(); }
                    int num = nextNode;
                    while(num != S){ // 도착점부터 시작점 찾아가면서 지나온곳들 edge에 저장
                        edge.push_back(make_pair(distParent[num], num));
                        num = distParent[num];
                    }
                }
                dist[nextNode] = dist[node] + nextCost;
            }
        }
    }   
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(true){
        cin >> N >> M;
        if(!N && !M){ break; }
        cin >> S >> D;
        for(int i=0; i<M; i++){
            cin >> U >> V >> P;
            arr[U].push_back(make_pair(V, P));
        }

        findPath(); // 최단거리 찾기

        removeEdge(); // 최단 거리에 속하는 간선 삭제

        check = true;
        findPath(); // 거의 최단 거리 찾기
        
        if(dist[D] == 1e9){  dist[D] = -1; }
        cout << dist[D] << "\n";

        for(int i=0; i<=N; i++){ arr[i].clear(); }
        edge.clear();
        memset(distParent, 0, sizeof(distParent));
        check = false;
    }

    return 0;
}




// 시간초과 
// #include <iostream>
// #include <string.h>
// #include <vector>
// #include <algorithm>
// #define MAX 987654321
// using namespace std;
// int N, M, S, D, U, V, P;
// int firstRoot = MAX, secondRoot = MAX;
// bool visited[501];
// vector<pair <int, int> > arr[501], removeRoot;

// void secondShortRoot(int idx, int sum){
//     if(idx == D){ secondRoot = min(secondRoot, sum); return; }

//     for(int i=0; i<arr[idx].size(); i++){
//         if(!visited[arr[idx][i].first]){
//             visited[arr[idx][i].first] = true;
//             secondShortRoot(arr[idx][i].first, sum + arr[idx][i].second);
//         }
//     }
// }

// void shortRoot(int idx, int sum, vector<pair <int, int> > vec){
//     if(idx == D){
//         if(firstRoot > sum){
//             firstRoot = sum;
//             removeRoot = vec;
//         }
//         return;
//     }

//     for(int i=0; i<arr[idx].size(); i++){
//         if(!visited[arr[idx][i].first]){
//             visited[arr[idx][i].first] = true;
//             vec.push_back(make_pair(idx, arr[idx][i].first));
//             shortRoot(arr[idx][i].first, sum + arr[idx][i].second, vec);
//             vec.pop_back();
//             visited[arr[idx][i].first] = false;
//         }
//     }
// }

// int main(void){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     while (true){
//         cin >> N >> M;
//         if(!N && !M){ return 0; }
//         cin >> S >> D;
//         for(int i=0; i<M; i++){
//             cin >> U >> V >> P;
//             arr[U].push_back(make_pair(V, P));
//         }
        
//         vector<pair <int, int> > temp;
//         shortRoot(S, 0, temp);
//         for(int i=0; i<removeRoot.size(); i++){
//             for(int j=0; j<arr[removeRoot[i].first].size(); j++){
//                 if(arr[removeRoot[i].first][j].first == removeRoot[i].second){
//                     arr[removeRoot[i].first].erase(arr[removeRoot[i].first].begin() + j);
//                 }
//             }
//         }

//         memset(visited, 0, sizeof(visited));
//         secondShortRoot(S, 0);
        
//         if(secondRoot == MAX){ secondRoot = -1; }
//         cout << secondRoot << "\n";
//         memset(visited, 0, sizeof(visited));
//         firstRoot = secondRoot = MAX;
//         removeRoot.clear();
//         for(int i=0; i<N; i++){ arr[i].clear(); }
//     }
//     return 0;
// }
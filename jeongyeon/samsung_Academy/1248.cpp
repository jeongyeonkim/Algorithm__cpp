// [S/W 문제해결 응용] 3일차 - 공통조상
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int test_case, T, V, E;
int nearParent, subtreeSize;
int depth[3], input[3];
vector<int> parent[10001];
int child[10001];

void treeSize(int i){
    subtreeSize++;

    if(parent[i].empty()){ return; }
    for(int j=0; j<parent[i].size(); j++){ treeSize(parent[i][j]); }
}

void findParent(int x, int y){
    while (depth[1] != depth[2]){
        if(depth[1] > depth[2]){
            x = child[x];
            depth[1]--;
        }else if(depth[2] > depth[1]){
            y = child[y];
            depth[2]--;
        }
    }
    
    while (child[x] != child[y]){
        x = child[x];
        y = child[y];
    }
    nearParent = child[x];
}

int findDepth(int x){
    int cnt = 0;
    int i = x;

    while(child[i] != 0){
        cnt++;
        i = child[i];
    }
    return cnt;
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> V >> E >> input[1] >> input[2];
        for(int i=0; i<E; i++){
            int x = 0, y = 0;
            cin >> x >> y;
            parent[x].push_back(y);
            child[y] = x;
        }

        depth[1] = findDepth(input[1]);
        depth[2] = findDepth(input[2]);

        findParent(input[1], input[2]);
        treeSize(nearParent);


        cout << "#" << test_case << " " << nearParent << " " << subtreeSize << "\n"; 
        nearParent = subtreeSize = 0;
        memset(child, 0, sizeof(child));
        for(int i=0; i<=V; i++){parent[i].clear(); }
    }
    return 0;
}
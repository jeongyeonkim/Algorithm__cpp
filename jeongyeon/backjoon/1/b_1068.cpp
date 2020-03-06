// 트리
#include <iostream>
#include <vector>
using namespace std;
int N, rootNode, result, removeNode;
vector<int> child[51];

void tree(int idx){
    if(idx == removeNode){ return; }
    if(child[idx].empty()){ result++; return; }

    for(int i=0; i<child[idx].size(); i++){
        if(child[idx][i] == removeNode){  }
        tree(child[idx][i]);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        int a = 0; cin >> a;
        if(a == -1){ rootNode = i; }
        else{ child[a].push_back(i); }
    }
    cin >> removeNode;
    child[removeNode].clear();

    if(rootNode != removeNode){ tree(rootNode); }

    cout << result << "\n";
}
// 트리
#include <iostream>
#include <vector>
using namespace std;
int N, rootNode, result, removeNode, p;
vector<int> child[51], parent[51];

int tree(int idx){
   int cnt = 0;
   if(child[idx].size() == 0){ return 1; }

   for(int i=0; i<child[idx].size(); i++){
       cnt += tree(child[idx][i]);
   }
   return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        int a = 0; cin >> a;
        if(a == -1){ rootNode = i; }
        else{
            child[a].push_back(i);
            parent[i].push_back(a);
        }
    }
    cin >> removeNode;
    if(!parent[removeNode].size()){ cout << 0; return 0; }
    p = parent[removeNode][0];
    for(int i=0; i<child[p].size(); i++){
        if(child[p][i] == removeNode){ child[p].erase(child[p].begin()+i); break; }
    }

    cout << tree(rootNode) << "\n";
}
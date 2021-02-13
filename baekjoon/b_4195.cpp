// 친구 네트워크
#include <iostream>
#include <string.h>
#include <map>
#define MAX 200002
using namespace std;
map<string, int> name;
int T, N;
string str1, str2;
int node[MAX], name_num[MAX];

int find(int u){
    if(u == node[u]){ return u;}
    return node[u] = find(node[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v){ return; }
    if(u > v){ swap(u, v); }
    node[u] = v;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--){
        int cnt = 1;
        cin >> N;
        for(int i=1; i<=N*2; i++){
            node[i] = i;
            name_num[i] = 1;
        }
        for(int i=0; i<N; i++){
            cin >> str1 >> str2;
            if(name.count(str1) == 0){ name[str1] = cnt++; }
            if(name.count(str2) == 0){ name[str2] = cnt++; }


        }

        name.clear();
    }
    return 0;
}
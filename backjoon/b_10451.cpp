// 순열 사이클
#include <iostream>
#include <string.h>
using namespace std;
int T, N, result;
int node[1002];
bool checkNode[1002];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> N;
        for(int i=1; i<=N; i++){ cin >> node[i]; }

        for(int i=1; i<=N; i++){
            if(!checkNode[i]){ // 다음 노드 방문 하지 않았을 경우
                result++;
                checkNode[i] = true;
                int nextNode = node[i];

                while (!checkNode[nextNode]){ // 같은 사이클 내 가능한 노드 방문
                    checkNode[nextNode] = true;
                    nextNode = node[nextNode];
                }
            }
        }
        
        cout << result << "\n";
        result = 0;
        memset(node, 0, sizeof(node));
        memset(checkNode, 0, sizeof(checkNode));
    }
    
}
// 키 순서
// 플로이드 와샬 알고리즘
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, a, b, result;
int arr[501][501], node[501];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){ // 배열 최대값으로 
        for(int j=1; j<=N; j++){
            if(i != j){ arr[i][j] = 1e9; }
        }
    }
    for(int i=0; i<M; i++){
        cin >> a >> b;
        arr[a][b] = 1; // 가중치 1
    }

    for(int i=1; i<=N; i++){ // 플로이드
        for(int a=1; a<=N; a++){
            for(int b=1; b<=N; b++){
                arr[a][b] = min(arr[a][b], arr[a][i] + arr[i][b]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j] != 1e9 && i != j){ // 노드 i까지 갈 수 있는 노드의 수
                node[i]++;
                node[j]++;
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(node[i] == N-1){ result++; } // 자신을 제외하고 모든 노드 방문 가능하면 ++
    }
    
    cout << result;
    return 0;
}
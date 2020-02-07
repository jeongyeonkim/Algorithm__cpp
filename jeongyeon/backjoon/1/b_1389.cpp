// 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, M, minresult = 987654321, cnt, result;
int arr[101][101], visited[101];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a = 0, b = 0;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    for(int i=1; i<=N; i++){
        queue<int> que;
        que.push(i);

        memset(visited, 0, sizeof(visited));
        cnt = 0;
        visited[i] = 1;

        while (!que.empty()){
            int x = que.front();
            que.pop();

            for(int j=1; j<=N; j++){
                if(visited[j]== 0 && arr[x][j] == 1){
                    que.push(j);
                    visited[j] = visited[x] + 1;
                }
            }
        }
        
        for(int j=1; j<=N; j++){
            if(i == j){ continue; }
            else{ cnt += (visited[j]) - 1; }
        }
        if(cnt < minresult){
            minresult = cnt;
            result = i;
        }
    }

    cout << result;
}
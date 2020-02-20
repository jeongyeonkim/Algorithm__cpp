// 소수 경로
#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>
#define MAX 10001
using namespace std;
int T, result, input, output;
int num[MAX];
int visited[MAX];

int find(){
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(input);
    visited[input] = 1;

    while (!que.empty()){
        int x = que.front();
        que.pop();

        if(x == output){ return visited[x]-1; }

        // 자리 수 저장
        int temp[4] = {x/1000, (x/100)%10, (x/10)%10, x%10};

        for(int i=0; i<4; i++){
            for(int j=0; j<10; j++){
                int nx = 0;
                 for (int k = 0; k < 4; k++){
                     if(i != k){ nx += temp[k] * pow(10, 3-k); }
                     else{ nx += j * pow(10, 3-k); }
                    // 1000의 자리가 0이면 안됨
                     if(num[nx] == 0 && visited[nx] == 0 && nx/1000 != 0){
                         visited[nx] = visited[x] + 1;
                         que.push(nx);
                     }
                }
            }
        }
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    num[1] = 1;
    // 미리 소수 판별할 배열 만들어 놓음
    for(int i=2; i<MAX; i++){
        if(num[i] == 1){ continue; }
        for(int j = i*2; j<MAX; j+=i){
            num[j] = 1;
        }
    }

    while (T--){
        cin >> input >> output;

        result = find(); 
        if(result == -1){ cout << "Impossible" << "\n"; }
        else{ cout << result << "\n"; }
    }
}
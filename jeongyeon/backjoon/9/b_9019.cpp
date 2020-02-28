// DSLR
#include <iostream>
#include <string.h>
#include <queue>
#define MAX 10000
using namespace std;
int T, A, B;
int visited[MAX];
// 이전 숫자 저장
int before[MAX];
// 사용한 계산기 저장
char after[MAX];

void printResult(int x, int y){
    if(x != y){
        printResult(x, before[y]);
        cout << after[y];
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> A >> B;
        queue<int> que;
        que.push(A);
        visited[A] = 1;

        while (!que.empty()){
            int x = que.front();
            que.pop();

            if(x == B){ printResult(A, B); break; }

            int D = (2*x)%MAX;
            if(visited[D] == 0){
                visited[D] = 1;
                que.push(D);
                after[D] = 'D';
                before[D] = x; 
            }

            int S = 0;
            if(x == 0){ S = 9999; }
            else{ S = x - 1; }
            if(visited[S] == 0){
                visited[S] = 1;
                que.push(S);
                after[S] = 'S';
                before[S] = x; 
            }

            int L = x%1000*10 + x/1000;
            if(visited[L] == 0){
                visited[L] = 1;
                que.push(L);
                after[L] = 'L';
                before[L] = x; 
            }

            int R = (x/10) + (x%10)*1000;
            if(visited[R] == 0){
                visited[R] = 1;
                que.push(R);
                after[R] = 'R';
                before[R] = x; 
            }
        }
        cout << "\n";
        memset(visited, 0, sizeof(visited));
    }
}
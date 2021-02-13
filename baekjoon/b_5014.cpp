// 스타트 링크
#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D, result = -1;
int visited[1000001];
queue<int> que;

int main(void){
    cin >> F >> S >> G >> U >> D;
    que.push(S);
    visited[S]++;

    while (!que.empty()){
        int x = que.front();
        que.pop();

        if(x == G){ result = visited[G] -1; break; }
        int nx[2] = {x + U, x - D};

        for(int i=0; i<2; i++){
            if(nx[i] <= 0 || nx[i] > F){ continue; }
            if(visited[nx[i]] == 0){
                visited[nx[i]] = visited[x] + 1;
                que.push(nx[i]);
            }
        }
    }

    if(result == -1){ cout << "use the stairs"; }
    else{ cout <<  result; }
}
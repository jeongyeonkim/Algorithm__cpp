// 게리멘더링
#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#define MAX 987654321
using namespace std;
int N, result = MAX;
int people[11], nearArea[11][11];
bool visited[11], selected[11];

// 인구 수 차이 구하기
void difference(){
    int sumA = 0, sumB =0;
    for(int i=1; i<=N; i++){
        if(selected[i]){ sumA += people[i]; }
        else{ sumB += people[i]; }
    }
    result = min(result, abs(sumA - sumB));
}

// 구역 0, 1로 나눔
void DFS(int x, int status){
    visited[x] = true;
    
    for(int i=1; i<=N; i++){
        if(visited[i]){ continue; }
        if(status == 1){
            if(selected[i] && nearArea[x][i]){
                visited[i] = true;
                DFS(i, status);
            }
        }else{
            if(!selected[i] && nearArea[x][i]){
                visited[i] = true;
                DFS(i, status);
            }
        }
    }
}

void divided(){
    memset(visited, 0, sizeof(visited));
    for(int i=1; i<=N; i++){
        if(selected[i]){ DFS(i, 1); break; }
    }
    for(int i=1; i<=N; i++){
        if(!selected[i]){ DFS(i, 0); break; }
    }
    for (int i = 1; i <= N; i++) {
		if (!visited[i]){ return; }
    }
    difference();
}

// 영역 선택
void selectArea(int n, int cnt){
    // 모든 영역 다 넣으면 return
    if(cnt >= N){ return; }
    if(cnt >= 1){ divided(); }

    for(int i=n; i<=N; i++){
        if(selected[i]){ continue; }
        selected[i] = true;
        selectArea(i, cnt + 1);
        selected[i] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){ cin >> people[i]; }
    for(int i=1; i<=N; i++){
        int city = 0;
        cin >> city;
        for(int j=0; j<city; j++){
            int a = 0; cin >> a;
            nearArea[i][a] = 1;
        }
    }

    selectArea(1, 0);

    if(result == MAX){ result = -1; }
    cout << result;
}
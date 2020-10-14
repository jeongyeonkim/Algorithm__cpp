// 차이를 최대로
// 1. N <= 8 이니까 브루트포스
// 2. 만들 수 있는 배열 조합
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N, result;
int arr[9], selected[9], visited[9];

void findMax(){
    int res = 0;
    for(int i=0; i<N-1; i++){ res += abs(selected[i] - selected[i+1]); }
    result = max(result, res);
}

void select(int cnt){
    if(cnt == N){
        findMax();
        return;
    }

    for(int i=0; i<N; i++){
        if(visited[i]){ continue; }
        visited[i] = 1;
        selected[cnt] = arr[i];
        select(cnt + 1);
        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }
    select(0);

    cout << result;
    return 0;
}
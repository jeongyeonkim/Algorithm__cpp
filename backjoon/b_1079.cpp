// 마피아
#include <iostream>
#include <algorithm>
using namespace std;
int N, result, K;
int arr[17][17], guilty[17], killed[17];

void dfs(int cnt, int day){
    if(killed[K] == 1 || cnt == 1){ // 은진이만 남았거나, 은진이 죽었을 경우
        result = max(result, day);
        return;
    }

    if(cnt % 2 == 0){ // 밤일 경우
        for(int i=0; i<N; i++){
            if(killed[i] == 1 || i == K){ continue; }
            killed[i] = 1;
            for(int j=0; j<N; j++){
                if(!killed[j]){ guilty[j] += arr[i][j]; }
            }
            dfs(cnt - 1, day + 1);
            for(int j=0; j<N; j++){
                if(!killed[j]){ guilty[j] -= arr[i][j]; }
            }
            killed[i] = 0;
        }
    }
    else{ // 낮일 경우
        int score = 0, idx = 0;
        for(int i=0; i<N; i++){ // 점수 제일 높은 애 찾기
            if(killed[i] == 0 && score < guilty[i]){ idx = i; score = guilty[i]; }
        }

        if(idx == K){ result = max(result, day); return; } // 제일 높은 애가 은진이면 return
        killed[idx] = 1;
        dfs(cnt - 1, day);
        killed[idx] = 0;
    }
}


int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> guilty[i]; }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ cin >> arr[i][j]; }
    }
    cin >> K;
    dfs(N, 0);
    cout << result;
    return 0;
}
// 사다리 조작
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, H, result = 4;
bool visited[31][11];

bool check(){
    for(int i=1; i<=M; i++){
        int num = i;
        
        for(int j=1; j<=H; j++){
            if(visited[j][num]){ num++; }
            else if(visited[j][num-1]){ num--; }
        }
        if(num != i){ return false; }
    }
    return true;
}

void Ladder(int idx, int cnt){
    if(cnt >= result){ return; }
    if(result > 4){ return; }
    
    if(check()){
        if(result > cnt){ result = cnt; }
        return;
    }
    
    for(int i=idx; i<=H; i++){
        for(int j=1; j<M; j++){
            if(visited[i][j]){ continue; }
            if(j > 1 && visited[i][j-1]){ continue; }
            if(visited[i][j+1]){ continue; }

            visited[i][j] = true;
            Ladder(i, cnt + 1);
            visited[i][j] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    for(int i=0; i<N; i++){
        int a = 0, b = 0; cin >> a >> b;
        visited[a][b] = true;
    }
    
    Ladder(1, 0);

    if(result == 4){ result = -1; }
    cout << result;
    return 0;
}
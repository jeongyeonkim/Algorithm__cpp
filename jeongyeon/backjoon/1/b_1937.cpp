// 욕심쟁이 판다
#include <iostream>
#include <algorithm>
using namespace std;
int n, maxStart, result;
int arr[501][501], cntBamboo[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int Bamboo(int x, int y){
    // 이미 방문한 곳이면 리턴
    if(cntBamboo[x][y] != 0){ return cntBamboo[x][y]; }
    
    cntBamboo[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위 벗어나면 continue
        if(nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }
        // 현재 대나무 수 보다 적을 경우 continue
        if(arr[x][y] >= arr[nx][ny]){ continue; }
        
        cntBamboo[x][y] = max(cntBamboo[x][y], Bamboo(nx, ny) + 1);
    }

    return cntBamboo[x][y];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ cin >> arr[i][j]; }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result = max(result, Bamboo(i, j));
        }
    }

    cout << result;
    return 0;
}
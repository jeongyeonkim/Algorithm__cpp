// 집배원 한상덕
// two pointer + DFS 사용
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 1000000
using namespace std;
int N, startX, startY, result = MAX, cntK;
int arr[51][51], hard[51][51], visited[51][51];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> fatigue;

int DFS(int x, int y, int left, int right){
    if(visited[x][y] || hard[x][y] < left || hard[x][y] > right || x < 0 || y < 0 || x >= N || y >= N){ return 0; }

    visited[x][y] = 1;
    int cnt = 0;
    if(arr[x][y] == 1){ cnt++; }

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        cnt += DFS(nx, ny, left, right);
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char a; cin >> a;
            if(a == 'P'){ startX = i; startY = j; }
            else if(a == 'K'){ arr[i][j] = 1; cntK++; }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> hard[i][j];
            fatigue.push_back(hard[i][j]); // 피로도 범위 저장
        }
    }
    sort(fatigue.begin(), fatigue.end());
    fatigue.erase(unique(fatigue.begin(),fatigue.end()),fatigue.end()); // vector 중복 값 제거

    int j = 0;
    for(int i=0; i<fatigue.size(); i++){
        while (true){
            memset(visited, 0, sizeof(visited));
            if(DFS(startX, startY, fatigue[j], fatigue[i]) != cntK){ break; }

            result = min(result, fatigue[i] - fatigue[j]);
            j++;
        }
    }

    cout << result << "\n";
    return 0;
}
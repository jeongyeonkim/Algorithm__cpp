// 영역 구하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K, x1, y1, x2, y2, cnt;
int arr[100][100];
bool visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> result;

void Area(int x, int y){
    visited[x][y] = true;
    cnt++;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >=0 && nx < N && ny < M){
            if(arr[nx][ny] == 0 && !visited[nx][ny]){
                Area(nx, ny);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    //입력
    for(int i=0; i<K; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        y2--;
        x2--;
        for(int j=x1; j<=x2; j++){
            for(int z=y1; z<=y2; z++){ arr[j][z] = 1; }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0 && !visited[i][j]){
                // 방문한적 없고 안막혀 있으면 탐색 시작
                // 넓이 매번 리셋하고 시작.
                cnt = 0;
                Area(i, j);
                result.push_back(cnt);
            }
        }
    }
    // 출력
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}
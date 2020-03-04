// 드래곤 커브
#include <iostream>
#include <vector>
using namespace std;
int N, x, y, d, g, result;
int visited[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    while (N--){
        cin >> y >> x >> d >> g;
        visited[x][y] = 1;

        // arr에 방향 저장
        vector<int> arr;
        arr.push_back(d);
        for(int i=0; i<g; i++){
            // 이전 방향에 90도씩 회전해서 새로 저장
            vector<int> arrCopy = arr;

            for(int j=arrCopy.size()-1; j>=0; j--){
                arr.push_back((arrCopy[j]+1)%4);
            }
        }

        for(int i=0; i<arr.size(); i++){
            x += dx[arr[i]];
            y += dy[arr[i]];
            
            if(x < 0 || y < 0 || x > 100 || y > 100){ continue; }
            visited[x][y] = 1;
        }
    }
    
    // 꼭지점 4개 다 방문되어있으면 result++
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(visited[i][j] && visited[i+1][j] && visited[i][j+1] && visited[i+1][j+1]){ result++; }
        }
    }
    cout << result;
    return 0;
}
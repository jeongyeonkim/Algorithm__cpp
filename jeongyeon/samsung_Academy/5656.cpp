// [모의 SW 역량테스트] 벽돌 깨기

// 틀린 코드
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int T, result, N, W, H;
int maxHight;
vector<int> arr[12];
int visited[15][12];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void resetBrick(){
    for(int i=0; i<W; i++){
        if(!arr[i].empty()){
            for(int j=0; j<arr[i].size(); j++){
                if(arr[i][j] == 0){
                    arr[i].erase(arr[i].begin()+j);
                    --j;
                }
            }
        }
    }
}

void breakBrick(int x, int y){
    visited[x][y] = 1;

    if(arr[x][y] == 1){
        arr[x].insert(arr[x].begin()+y, 0);
        arr[x].erase(arr[x].begin()+y+1);
    }

    else if(arr[x][y] > 1){
        for(int i=1; i<=arr[x][y]; i++){
            for(int j=0; j<4; j++){
                int nx = x + dx[j]*i;
                int ny = y + dy[j]*i;

                if(ny < 0 || ny >= W || nx < 0 || nx >= arr[y].size()){ continue; }
                if(visited[nx][ny] == 0){
                    breakBrick(nx, ny);
                    
                }
            }
        }
        arr[x].insert(arr[x].begin()+y, 0);
        arr[x].erase(arr[x].begin()+y+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int test_case = 1; test_case<=T; test_case++){
        cin >> N >> W >> H;
        int input[H][W];
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){ cin >> input[i][j]; }
        }
        // 세로 하나가 스택1개
        // 입력 값 스택에 넣어줌
        for(int i=H-1; i>=0; i--){
            for(int j=0; j<W; j++){
                if(input[i][j] != 0){ arr[j].push_back(input[i][j]); }
            }
        }
        //벽돌 깨기
        for(int i=0; i<N; i++){
            int start=0;
            // 가장 높이가 높은 점 찾기 -> 구술 떨어트리는 곳
            for(int j=0; j<W; j++){
                if(maxHight < arr[j].size()){
                    maxHight = arr[j].size()-1;
                    start = j;
                }
            }
            memset(visited, 0, sizeof(visited));
            breakBrick(maxHight, start);
            resetBrick();
        }

        //남은 벽돌 카운트
        for(int i=0; i<W; i++){
            result += arr[i].size();
            cout << arr[i].size() << " ";
            arr[i].clear();
        }

        cout << "#" << test_case << " " << result << "\n";
        N = W = H = 0;
        result = maxHight = 0;
        memset(visited, 0, sizeof(visited));
    }


}
// 인구 이동
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;
int N, L, R, result, sum;
int arr[51][51], area[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair <int, int> > unionNat;

void population(int x, int y){
    sum += arr[x][y];
    area[x][y] = 1;
    unionNat.push_back(make_pair(x, y));

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
        if(!area[nx][ny] && abs(arr[x][y] - arr[nx][ny]) >= L &&  abs(arr[x][y] - arr[nx][ny]) <= R){
            population(nx, ny);
        }
    }
}

bool checkMove(){
    bool check = false;
    memset(area, 0, sizeof(area));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            // 아직 방문하지 않은 나라면 탐색 시작
            if(area[i][j] == 0){
                // 가능한 지역 좌표 unionNat에 저장
                unionNat.clear();
                sum = 0;
                population(i, j);
                // 첫 나라말고 다른 나라도 있으면 연합 형성
                if(unionNat.size() > 1){
                    for(int v=0; v<unionNat.size(); v++){
                        arr[unionNat[v].first][unionNat[v].second] = sum/unionNat.size();
                    }
                    check = true;
                }
            }
        }
    }

    return check;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ cin >> arr[i][j]; }
    }

    while (checkMove()){ result++; }
    cout << result;
}
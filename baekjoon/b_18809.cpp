// Gaaaaaaaaaarden
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, G, R, result;
int graden[51][51];
vector<pair <int,int> > enableLand;
vector<int> indexGRLand;
int gradenCopyColor[51][51];
int gradenCopyTime[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y;
    int color;
    int arriveTime;
};

// 1. 배양액을 넣을 수 있는 곳의 위치를 enableLand에 저장
// 2. indexGRLand에 R, G의 배양액 갯수 넣고 나머지는 0으로 넣음 > 조합 만들기 위해
// 3. permutation사용
// 4. makeFlower에서 BFS 실행
// 5. 구조체에 각 배양액의 도착 시간 저장함 > 같은 시간에 도착하면 꽃을 만들어야 하기 때문에 
void makeFlower(){
    int countFlower = 0;
    queue<info> que;
    memset(gradenCopyColor, 0, sizeof(gradenCopyColor));
    memset(gradenCopyTime, 0, sizeof(gradenCopyTime));

    for(int i=0; i<indexGRLand.size(); i++){
        if(indexGRLand[i] == 5){ // G
            gradenCopyColor[enableLand[i].first][enableLand[i].second] = 5;
            que.push({enableLand[i].first, enableLand[i].second, 5, 0});
        }else if(indexGRLand[i] == 6){ // R
            gradenCopyColor[enableLand[i].first][enableLand[i].second] = 6;
            que.push({enableLand[i].first, enableLand[i].second, 6, 0});
        }
    }

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int color = que.front().color;
        int arriveTime = que.front().arriveTime;
        que.pop();

        if(gradenCopyColor[x][y] == 10){ continue; }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || graden[nx][ny] == 0 || gradenCopyColor[nx][ny] == 10){ continue; }

            if(gradenCopyColor[nx][ny] == 0){
                gradenCopyColor[nx][ny] = color;
                gradenCopyTime[nx][ny] = arriveTime + 1;
                que.push({nx, ny, color, arriveTime + 1});
            } else if(arriveTime + 1 == gradenCopyTime[nx][ny]){
                if((color == 5 && gradenCopyColor[nx][ny] == 6) || (color == 6 && gradenCopyColor[nx][ny] == 5)){
                    gradenCopyColor[nx][ny] = 10;
                    countFlower++;
                }
            }
        }
    }

    result = max(result, countFlower);
}

void pushColor(int color, int cnt){
    if(cnt <= 0){ return; }
    for(int i=0; i<cnt; i++){
        indexGRLand.push_back(color);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> graden[i][j];
            if(graden[i][j] == 2){
                enableLand.push_back(make_pair(i, j));
            }
        }
    }
    pushColor(5, G);
    pushColor(6, R);
    pushColor(0, ((int)enableLand.size() - G - R));
    sort(indexGRLand.begin(), indexGRLand.end());

    do{
        makeFlower();
    } while (next_permutation(indexGRLand.begin(), indexGRLand.end()));

    cout << result;
    return 0;
}
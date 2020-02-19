// 연구소
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int N, M, result;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[9][9], copyArr[9][9], check[9][9];
vector<pair <int, int> > area, virus;

void countArea(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(copyArr[i][j] == 0){ cnt++; }
        }
    }
    // 최대 안전지역 저장
    result = max(result, cnt);
}

void spreadVirus(){
    memset(check, 0, sizeof(check));

    // 바이러스 지역 BFS
    for(int i=0; i<virus.size(); i++){
        queue<pair <int, int> > que;
        que.push(make_pair(virus[i].first, virus[i].second));
        check[virus[i].first][virus[i].second] = 1;

        while (!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
                if(check[nx][ny] == 0 && copyArr[nx][ny] == 0){
                    copyArr[nx][ny] = 2;
                    check[nx][ny] = 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }

    countArea();
}

void makeWall(int cnt){
    // 벽 세개가 세워지면 바이러스 퍼트리고 안전지역 카운트
    if(cnt == 3){
        for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				copyArr[i][j] = arr[i][j];
	
		return spreadVirus();
    }

    for(int i=0; i<area.size(); i++){
		if(arr[area[i].first][area[i].second] == 0){
            arr[area[i].first][area[i].second] = 1;
            makeWall(cnt + 1);
            arr[area[i].first][area[i].second] = 0;
        }
	}
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            // 벽을 세울 수 있는 자리 area에 저장
            if(arr[i][j] == 0){ area.push_back(make_pair(i, j)); }
            // 바이러스 시작점들 virus에 저장
            if(arr[i][j] == 2){ virus.push_back(make_pair(i, j)); }
        }
    }
    // 세울 수 있는 곳들 브루트포스로 접근
    for(int i=0; i<area.size(); i++){
        if(arr[area[i].first][area[i].second] == 0){
            arr[area[i].first][area[i].second] = 1;
            makeWall(1);
            arr[area[i].first][area[i].second] = 0;
        }
        
    }
    
    cout << result;
    return 0;
}
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector<vector<int>> copyPic;
int visited[101][101], areaSize, N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void kakaoColor(int x, int y){ // DFS 실행
    visited[x][y] = 1;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N){ continue; }
        if(!visited[nx][ny] && copyPic[x][y] == copyPic[nx][ny]){
            areaSize++; // 해당 영역 넓이 구하기 위해 영역을 넓힐때마다 ++
            kakaoColor(nx, ny);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    copyPic = picture;
    N = n; M = m;
    memset(visited, 0, sizeof(visited));
    vector<int> answer(2);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && picture[i][j] != 0){
                areaSize = 1;
                number_of_area++; // DFS 탐색 갯수 저장

                kakaoColor(i, j);

                max_size_of_one_area = max(max_size_of_one_area, areaSize);
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
// 파핑파핑 지뢰찾기
#include <iostream>
#include <string.h>
using namespace std;
int test_case, T, N;
int result;
char arr[301][301];
int visited[301][301];
int dx[8] = {0, 1, -1, 0, -1, 1, 1, -1};
int dy[8]= {1, 0, 0, -1, -1, 1, -1, 1};

// 주위 지뢰 갯수 찾기
int findMine(int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
        if(arr[nx][ny] == '*'){ cnt++; }
    }
    return cnt;
}

void popping(int x, int y){
    if(arr[x][y] == '0'){
        // 주위에 지뢰 없으면 그 클릭한 자리 주위 8자리 방문해서 숫자로 변환
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
            if(visited[nx][ny] == 0){
                visited[nx][ny] = 1;
                arr[nx][ny] = findMine(nx, ny) + '0';
                popping(nx, ny);
            }
        }
    }
    return;
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ cin >> arr[i][j]; }
        }

        // 주위에 지뢰가 없는 곳 부터 클릭
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // 주위 지뢰 갯수가 0이고, 아직 숫자로 변환되지 않은 곳이면 클릭
                if(findMine(i, j) == 0 && arr[i][j] == '.'){
                    visited[i][j] = 1;
                    result++;
                    arr[i][j] = '0'; 
                    popping(i, j);
                }
            }
        }

        // 남은 곳 클릭
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j] == '.'){
                    visited[i][j] = 1;
                    result++;
                    arr[i][j] = findMine(i, j) + '0'; 
                }
            }
        }
    
        cout << "#" << test_case << " " << result << "\n"; 
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        result = 0;
    }
    return 0;
}
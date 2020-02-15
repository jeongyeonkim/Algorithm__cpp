// 파핑파핑 지뢰찾기
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
int test_case, T, N;
int result;
string arr[301][301];
int visited[301][301];
int dx[8] = {0, 1, -1, 0, -1, 1, 1, -1};
int dy[8]= {1, 0, 0, -1, -1, 1, -1, 1};

void popping(int x, int y){
    int cnt = 0;
    visited[x][y] = 1;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
        if(arr[nx][ny] == "*"){ cnt++; }
    }
    arr[x][y] = to_string(cnt);
    
    if(cnt == 0){
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
            if(visited[nx][ny] == 0){ popping(nx, ny); }
        }
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        for(int i=0; i<N; i++){
            string a; cin >> a;
            for(int j=0; j<N; j++){ arr[i][j] = a.at(j); }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j] == "."){
                    popping(i, j);
                    result++;
                    cout << i << " " << j << "\n";
                }
            }
        }
    
        cout << "#" << test_case << " " << result << "\n"; 
        memset(arr, 0, sizeof(arr));
        result = 0;
    }
    return 0;
}
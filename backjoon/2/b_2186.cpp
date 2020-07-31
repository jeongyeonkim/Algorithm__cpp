// 문자판
#include <iostream>
#include <string.h>
using namespace std;
int N, M, K, result;
char arr[101][101];
int visited[101][101][81];
string str;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y, int idx){
	if(visited[x][y][idx] != -1){ return visited[x][y][idx]; }
	if(idx >= str.length()){ return 1; }
	visited[x][y][idx] = 0;
	
	for(int i=0; i<4; i++){
		for(int j=1; j<=K; j++){
			int nx = x + dx[i]*j;
			int ny = y + dy[i]*j;
			if(nx < 0 || ny < 0 || nx >= N || ny >= M){ break; }
			if(arr[nx][ny] != str[idx]){ continue; }
			
			visited[x][y][idx] += dfs(nx, ny, idx + 1);
		}
	}
	return visited[x][y][idx];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    memset(visited, -1, sizeof(visited));
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<M; j++){ arr[i][j] = str[j]; }
    }
    cin >> str;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == str[0]){
                result += dfs(i, j, 1);
            }
        }
    }

    cout << result;
    return 0;
}
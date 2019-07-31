#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int input[26][26];
int visit[26][26];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
vector<int> result;
int N, cnt;

void DFS(int x, int y){
    cnt++;
    visit[x][y] =1;
    for(int i=0; i<4; i++){
        int nx = x +dx[i], ny = y +dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < N){
            if (visit[nx][ny] == 0 && input[nx][ny] == 1)
                DFS(nx, ny);
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            scanf("%1d", &input[i][j]);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(input[i][j] == 1 && visit[i][j] == 0){
                cnt=0;
                DFS(i, j);
                result.push_back(cnt);
            }
        }   
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++)
        cout << result[i] << "\n";

    return 0;
}
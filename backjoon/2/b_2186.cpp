// 문자판
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M, K, result;
char arr[101][101];
string str;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y;
    string word;
};

void bfs(int n, int m){
    queue<info> que;
    string temp;
    temp += str[0];
    que.push({n, m, temp});

    while (!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        string word = que.front().word;
        que.pop();

        if(word.length() >= str.length()){
            if(!word.compare(str)){
                result++;
            }
            continue;
        }

        for(int i=0; i<4; i++){
            int nx = x, ny = y;
            for(int j=1; j<=K; j++){
                nx += dx[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M){ break; }

                if(arr[nx][ny] == str[word.length()]){
                    que.push({nx, ny, word+arr[nx][ny]});
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j];
        }
    }
    cin >> str;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == str[0]){
                bfs(i, j);
            }
        }
    }

    cout << result;
    return 0;
}
// 열쇠
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int T, h, w, result;
char arr[105][105];
int visited[105][105], key[27];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void findDocument(){
    queue<pair <int, int> > que;
    visited[0][0] = 1;
    que.push(make_pair(0, 0));

    while (!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > h+1 || ny > w+1){ continue; }
            if(arr[nx][ny] == '*' || visited[nx][ny] == 1){ continue; }
            if(arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z' && key[arr[nx][ny] - 'A'] == 0){ // 열쇠가 없는있는 문을 만났을 경우
                continue;
            }

            if(arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z'){ // 열쇠 만났을 경우
                key[arr[nx][ny] - 'a'] = 1;
                arr[nx][ny] = '.';
                memset(visited, 0, sizeof(visited)); // 새로운 열쇠를 가졌으니 방문 초기화
                while (!que.empty()){ que.pop(); } // que도 clear
            }
            else if(arr[nx][ny] == '$'){ // 문서 만났을 경우
                arr[nx][ny] = '.';
                result++;
            }

            visited[nx][ny] = 1;
            que.push(make_pair(nx, ny));
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> h >> w;
        memset(arr, '.', sizeof(arr));
        memset(visited, 0, sizeof(visited));
        memset(key, 0, sizeof(key));
        result = 0;

        for(int i=1; i<=h; i++){
            string str; cin >> str;
            for(int j=0; j<w; j++){ arr[i][j+1] = str[j]; }
        }

        string s; cin >> s;
        if(s.compare("0") != 0){ // 처음에 갖고 있는 key
            for(int i=0; i<s.length(); i++){ key[s[i] - 'a'] = 1; }
        }

        findDocument();

        cout << result << "\n";
    }
    return 0;
}
// // 퍼즐
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <string.h>
// using namespace std;
// int arr[4][4], result = 1e9, X, Y;
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};

// struct info{
//     int x, y, cnt, dir, map[4][4];
// };
// queue<info> que;

// bool check(int t[4][4]){
//     int num = 1;
//     for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             if(i == 2 && j == 2){ break; }
//             if(num++ != t[i][j]){ return false; }
//         }
//     }
//     return true;
// }

// int main(void){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             cin >> arr[i][j];
//             if(arr[i][j] == 0){ X = i; Y = j; }
//         }
//     }
//     que.push({X, Y, 0, -1, arr});

//     while (!que.empty()){
//         int x = que.front().x;
//         int y = que.front().y;
//         int tmp[4][4]; memset(tmp, 0, sizeof(tmp));
//         for(int i=0; i<3; i++){
//             for(int j=0; j<3; j++){ tmp[i][j] = que.front().map[i][j]; }
//         }
//         int cnt = que.front().cnt;
//         int dir = que.front().dir;
//         que.pop();

//         if(check(tmp)){ result = cnt; break; }

//         for(int i=0; i<4; i++){
//             if(dir == (i + 2) % 4){ continue; }
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3){ continue; }

//             arr[x][y] = arr[nx][ny];
//             arr[nx][ny] = 0;
//             que.push({nx, ny, cnt + 1, i, tmp});
//             arr[nx][ny] = arr[x][y];
//             arr[x][y] = 0;
//         }

//     }
    

//     if(result == 1e9){ cout << -1; }
//     else{ cout << result; }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;
int arr[4][4], r, c, ans = 1e9;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool check[4][4];
map<string, int> m;
struct pos {
   int row, col;
};
queue<pos> q;

void init() {
   for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
         cin >> arr[i][j];
         if (arr[i][j] == 0) {
            r = i; c = j;
            q.push({ i,j });
         }
      }
   }
}

void bfs() {
   string a = "";
   for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
         a += to_string(arr[i][j]);
      }
   }
   m[a] = 1;//초기 값 저장

   int cnt = 0;
   while (!q.empty()) {
      pos cur = q.front(); q.pop();
      int cr = cur.row; int cc = cur.col;//0의 정보를 가진 위치

      for (int i = 0; i < 4; i++) {
         int nr = cr + dy[i]; int nc = cc + dx[i];
         if (nr < 1 || nr>3 || nc < 1 || nc>3) continue;

         int tmp = arr[nr][nc];
         arr[cr][cc] = tmp; arr[nr][nc] = 0;//일단 숫자 변경

         string aa = "";
         for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
               aa += to_string(arr[j][k]);
            }
         }

         if (aa == "123456780") {//완성이면
            cnt++;
            ans = cnt; return;
         }
         
         cout << aa << '\n';

         if (m.count(aa) == 0) {//새로운 녀석이면
            m[aa] = 1;
            q.push({ nr,nc });
            cnt++;

         }
         else {//아니면
            arr[cr][cc] = 0;
            arr[nr][nc] = tmp;
         }
      }
   }
}


int main(void) {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   init();
   bfs();
   if (ans == 1e9) ans = -1;
   cout << ans;
   return 0;
}
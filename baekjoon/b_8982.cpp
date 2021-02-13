// 수족관 1
#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}



// #include <iostream>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <queue>
// #include <climits>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> pii;
// struct Point {
// 	int r, c;
// 	int height;
// };
// int N, M;
// int mat[51][51];
// bool visit[51][51];
// int mv[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
// queue<Point> q;
// bool flag;
// void bfs(Point p) {
// 	int r = p.r;
// 	int c = p.c;
// 	int h = p.height;
// 	for (int i = 0; i < 4; i++) {
// 		int nr = r + mv[i][0];
// 		int nc = c + mv[i][1];
// 		if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
// 			flag = false;
// 			continue;
// 		}
// 		if (visit[nr][nc] || mat[nr][nc] >= h) continue;
// 		q.push({ nr, nc, h });
// 		visit[nr][nc] = true;
// 	}
// }
// void solve() {
// 	int sum = 0;
// 	for (int h = 1; h <= 9; h++) {
// 		for (int i = 0; i < N; i++) {
// 			for (int j = 0; j < M; j++) {
// 				if (visit[i][j]) continue;
// 				if (mat[i][j] >= h) continue;
				
// 				q.push({ i,j,h });
// 				visit[i][j] = true;
// 				int cnt = 0;
// 				flag = true;
// 				while (!q.empty()) {
// 					Point temp = q.front(); q.pop();
// 					bfs(temp);
// 					cnt++;
// 				}
// 				if (flag) {
// 					sum += cnt;
// 				}
// 			}
// 		}
// 		memset(visit, false, sizeof(visit));
// 	}
// 	cout << sum;
//  }
// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> N >> M;
// 	string s;
// 	for (int i = 0; i < N; i++) {
// 		cin >> s;
// 		for (int j = 0; j < M; j++) {
// 			mat[i][j] = s[j] - '0';
// 		}
// 	}
// 	solve();
// }
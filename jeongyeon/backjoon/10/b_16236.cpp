// 아기 상어
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 21
using namespace std;
int n, Time;
bool isEnd;
int map[MAX][MAX];
bool check[MAX][MAX];
// 상좌우하
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
struct shark {
	int r, c, size, cnt= 0;
    shark(int r, int c){r = r; c = c;}
}baby;
bool isBound(int r, int c) {
	if (r > -1 && c > -1 && r < n && c < n) return true;
	return false;
}
void selectPrey(queue<pair<int, int>> &prey) {
	int prior_x = n, prior_y = n;
	while (!prey.empty()) {
		int x = prey.front().first;
		int y = prey.front().second;
		prey.pop();
		if (x < prior_x) {
			prior_x = x;
			prior_y = y;
		}
		else if (x == prior_x) {
			if (y < prior_y) {
				prior_y = y;
			}
		}
	}
	map[baby.r][baby.c] = 0;
	map[prior_x][prior_y] = 9;
	baby.r = prior_x;
	baby.c = prior_y;
	baby.cnt++;
	if (baby.cnt == baby.size) {
		baby.size++;
		baby.cnt = 0;
	}
}
void findPrey(int row, int col) {
	queue<pair<int, int>> q, prey;
	q.push({ row, col });
	memset(check, 0, sizeof(check));
	check[row][col] = true;
	int part_time = 0;
	while (!q.empty()) { // 순회할 때마다 1초 증가
		part_time++;
		int len = q.size();
		for (int i = 0; i < len; ++i) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int x = r + dx[j];
				int y = c + dy[j];
				if (isBound(x, y) && baby.size >= map[x][y] && !check[x][y]) {
					if (baby.size > map[x][y] && map[x][y] > 0) {
						prey.push({ x, y });
					}
					check[x][y] = true;
					q.push(shark{ x, y });
				}
			}
		}
		if (!prey.empty()) {
			selectPrey(prey);
			Time += part_time;
			return;
		}
	}
	isEnd = true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) { // 아기 상어 정보
				baby.r = i;
				baby.c = j;
				baby.size = 2;
			}
		}
	}
	while (!isEnd) {
		findPrey(baby.r, baby.c);
	}
	printf("%d\n", Time);
	return 0;
}
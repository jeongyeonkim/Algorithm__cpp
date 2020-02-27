#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct INFO {
	int x, y, type;
};

int n, m, cctv_cnt, result = 65;
int room[9][9];
int selected[9];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int type_two[2][2] = {{0, 1}, {2, 3}};
int type_three[4][2] = { {0, 3}, {1, 3}, {0, 2}, {1, 2} };
int type_four[4][3] = { {2, 0, 3}, {0, 3, 1}, {2, 1, 3}, {0, 2, 1} };
vector<INFO> cctv;

bool isBound(int x, int y) {
	if (x > -1 && y > -1 && x < n && y < m) return true;
	return false;
}

void task() {
	bool check[9][9] = { 0, };
	int type, res = 0;

	for (int i = 0; i < cctv.size(); ++i) {
		int dir = selected[i];
		int x = cctv[i].x, y = cctv[i].y;
		int nx, ny;

		if (cctv[i].type == 1) {
			nx = x + dx[dir];
			ny = y + dy[dir];
			while (isBound(nx, ny) && room[nx][ny] != 6) {
				if (!check[nx][ny] && room[nx][ny] == 0) {
					check[nx][ny] = true;
					res++;
				}
				nx += dx[dir];
				ny += dy[dir];
			}
		}

		else if (cctv[i].type == 2) {
			for (int j = 0; j < 2; ++j) {
				nx = x + dx[type_two[dir][j]];
				ny = y + dy[type_two[dir][j]];
				while (isBound(nx, ny) && room[nx][ny] != 6) {
					if (!check[nx][ny] && room[nx][ny] == 0) {
						check[nx][ny] = true;
						res++;
					}
					nx += dx[type_two[dir][j]];
					ny += dy[type_two[dir][j]];
				}
			}
		}

		else if (cctv[i].type == 3) {
			for (int j = 0; j < 2; ++j) {
				nx = x + dx[type_three[dir][j]];
				ny = y + dy[type_three[dir][j]];
				while (isBound(nx, ny) && room[nx][ny] != 6) {
					if (!check[nx][ny] && room[nx][ny] == 0) {
						check[nx][ny] = true;
						res++;
					}
					nx += dx[type_three[dir][j]];
					ny += dy[type_three[dir][j]];
				}
			}
		}

		else if (cctv[i].type == 4) {
			for (int j = 0; j < 3; ++j) {
				nx = x + dx[type_four[dir][j]];
				ny = y + dy[type_four[dir][j]];
				while (isBound(nx, ny) && room[nx][ny] != 6) {
					if (!check[nx][ny] && room[nx][ny] == 0) {
						check[nx][ny] = true;
						res++;
					}
					nx += dx[type_four[dir][j]];
					ny += dy[type_four[dir][j]];
				}
			}
		}

		else if (cctv[i].type == 5) {
			for (int j=0; j<4; j++) {
				nx = x + dx[j];
				ny = y + dy[j];
				while (isBound(nx, ny) && room[nx][ny] != 6) {
					if (!check[nx][ny] && room[nx][ny] == 0) {
						check[nx][ny] = true;
						res++;
					}
					nx += dx[j];
					ny += dy[j];
				}
			}
		}
	}

    // 전체 칸의 개수 - 탐색된 곳의 개수 - 벽의 개수 - cctv 개수 = 사각지대 개수
	res = (n * m) - res - cctv_cnt - cctv.size();
	result = min(result, res);
}

void selectDirection(int idx, int cnt) {
	if (cnt == cctv.size()) {
		task();
		return;
	}

	int cctv_type = cctv[idx].type;
	for (int i = 0; i < 4; ++i) {
        // 2번 cctv는 2가지  5번 cctv는 1가지 방향
		if (cctv_type == 2) { if (i == 2) break; }
		if(cctv_type == 5) { if (i == 1) break; }

		selected[idx] = i;
		selectDirection(idx + 1, cnt + 1);
		selected[idx] = -1;
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    memset(selected, -1, sizeof(selected));

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 5) { cctv.push_back({ i, j, room[i][j] }); }
			else if (room[i][j] == 6){ cctv_cnt++; }
		}
	}

	selectDirection(0, 0);
	cout << result << "\n";
}
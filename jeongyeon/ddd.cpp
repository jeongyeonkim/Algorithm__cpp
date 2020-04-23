#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN * MAXN;
// 방에서 위치를 나타내는 구조체
struct Pos {
	int r, c; // row, col
	Pos() {}
	Pos(int r, int c) : r(r), c(c) {}
} person[MAXN], stair[2]; // 사람, 계단

int n, m, s; // 방 크기, 사람 수, 계단 수(2)
int room[MAXN][MAXN];
int match[MAXN]; // 어떤 사람이 어떤 계단을 탔는지
int answer;
// 사람과 계단 사이의 거리
int dist(int p_idx, int s_idx) {
	int dx = abs(person[p_idx].r - stair[s_idx].r);
	int dy = abs(person[p_idx].c - stair[s_idx].c);
	return dx + dy;
}

void update() {
	int total_min_time = 0; // 모든 사람들이 계단 내려가는데 필요한 최소 시간
	// 계단은 고정 2개이다.
	for (int s_idx = 0; s_idx < 2; ++s_idx) {
		Pos &now_stair = stair[s_idx];
		int arrival_time[MAXN * 2] = { 0, }; // t시간일 때 계단에 도착하는 사람 수
		int current_stair[MAXT] = { 0, }; // t시간에일 때 계단을 내려가고 있는 사람 수 
		for (int p_idx = 0; p_idx < m; ++p_idx) {
			if (match[p_idx] == s_idx) {
				arrival_time[dist(p_idx, s_idx) + 1]++;
			}
		}
		int now_min_time = 0;

		for (int time = 1; time <= 20; ++time) {
			// time시간일 때 도착한 사람이 있을 때
			while (arrival_time[time] > 0) {
				arrival_time[time]--;

				int remain_time = room[now_stair.r][now_stair.c];
				
				for (int walk_time = time; walk_time < MAXT; ++walk_time) {
					if (current_stair[walk_time] < 3) {
						current_stair[walk_time]++;
						remain_time--;

						if (remain_time == 0) {
							now_min_time = max(now_min_time, walk_time + 1);
							break;
						}
					}
				}
			}
		}
		// 두 계단을 내려가는데 필요한 최소 시간 중 최댓값이 전체 계단을 내려가는데 필요한 최소 시간
		total_min_time = max(total_min_time, now_min_time);
	}
	answer = min(answer, total_min_time);
}

void dfs(int p_idx) {
	// 종료 조건
	if (p_idx == m) {
		update();
		return;
	}
	// 재귀호출
	for (int s_idx = 0; s_idx < 2; ++s_idx) {
		match[p_idx] = s_idx;
		dfs(p_idx + 1);
	}
}

int main() {
	int t; for(scanf("%d", &t); --t;) {
		scanf("%d", &n); m = s = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &room[i][j]);
				if (room[i][j] == 1) person[m++] = Pos(i, j);
				if (room[i][j] >= 2) stair[s++] = Pos(i, j);
			}
		}
		answer = 1e9;
		dfs(0);
		static int tc = 0;
		printf("#%d %d\n", ++tc, answer);
	}
	return 0;
}
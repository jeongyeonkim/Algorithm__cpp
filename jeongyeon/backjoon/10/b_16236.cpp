// 아기 상어
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int n, t;
bool eat = true;
int arr[21][21];
bool check[21][21];
// 상좌우하
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

struct shark { // cnt == 먹은 수
	int r, c, size, cnt= 0;
}baby;

void selectFish(queue<pair<int, int>> &prey) {
	int X = n, Y = n;

	while (!prey.empty()) {
		int x = prey.front().first;
		int y = prey.front().second;
		prey.pop();

		if(x < X) { X= x; Y = y; }
		else if(x == X) {
			if (y < Y) { Y = y; }
		}
	}
	arr[baby.r][baby.c] = 0;
	arr[X][Y] = 9;
	baby.r = X; baby.c = Y;
	baby.cnt++;
	if (baby.cnt == baby.size) {
		baby.size++;
		baby.cnt = 0;
	}
}

void findFish(int row, int col) {
	queue<pair<int, int> > q, fish;
	q.push(make_pair(row, col));
	memset(check, 0, sizeof(check));
	check[row][col] = true;
	int partT = 0;

	while (!q.empty()) { // 순회할 때마다 1초 증가
		partT++;
		int len = q.size();

		for(int i=0; i<len; i++){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for(int j=0; j<4; j++){
				int x = r + dx[j];
				int y = c + dy[j];

				if(x < 0 || y < 0 || x >=n || y >= n){ continue; }
				if(baby.size >= arr[x][y] && !check[x][y]){
					// 아기상어 크기보다 작으면 먹을 수 있는 물고기 담는 큐에 넣음
					if(baby.size > arr[x][y] && arr[x][y] > 0){
						fish.push(make_pair(x, y));
					}
					check[x][y] = true;
					q.push(make_pair(x, y));
				}
			}
		}
		if (!fish.empty()) {
			selectFish(fish);
			t += partT;
			return;
		}
	}
	// 먹이 없으면 false
	eat = false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 9) { // 아기 상어 정보
				baby.r = i;
				baby.c = j;
				baby.size = 2;
			}
		}
	}

	while(eat){
		findFish(baby.r, baby.c);
	}

	cout << t;
	return 0;
}
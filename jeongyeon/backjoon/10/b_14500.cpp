// 테트로미노
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result;
int arr[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void Tetromino(int x, int y){

}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> arr[i][j]; }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ Tetromino(i, j); }
    }

    cout << result;
    return 0;
}

// 모양 다 구현한 방법
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int N, M, result;
// int arr[501][501];
// int block[19][3][2] =  {
//     {{0, 1}, {0, 2}, {0, 3}}, // 일자모양
//     {{1, 0}, {2, 0}, {3, 0}},
//     {{0, 1}, {1, 0}, {1, 1}}, // 정사각형
//     {{1, 0}, {2, 0}, {2, 1}}, // 'ㄴ'자 모양
//     {{0, 1}, {0, 2}, {-1, 2}},
//     {{0, 1}, {1, 1}, {2, 1}},
//     {{0, 1}, {0, 2}, {1, 0}},
//     {{1, 0}, {1, 1}, {2, 1}}, // 'z' 모양
//     {{1, 0}, {1, -1}, {0, 1}},
//     {{1, 0}, {0, 1}, {-1, 1}},
//     {{0, -1}, {1, 0}, {1, 1}},
//     {{0, 1}, {-1, 1}, {-2, 1}}, // 'ㄴ' 반대 모양
//     {{0, 1}, {0, 2}, {1, 2}},
//     {{0, 1}, {1, 0}, {2, 0}},
//     {{1, 0}, {1, 1}, {1, 2}},
//     {{0, -1}, {1, 0}, {0, 1}}, // 'ㅗ' 모양
//     {{-1, 0}, {0, 1}, {1, 0}},
//     {{0, -1}, {-1, 0}, {0, 1}},
//     {{-1, 0}, {0, -1}, {1, 0}}
// };

// void Tetromino(int x, int y){
//     for(int i=0; i<19; i++){
//         int sum = arr[x][y];
//         bool check = true;
//         for(int j=0; j<3; j++){
//             int nx = x + block[i][j][0];
//             int ny = y + block[i][j][1];

//             if(nx >= 0 && ny >= 0 && nx < N && ny < M){ sum +=  arr[nx][ny]; }
//             else{ check = false; break; }
//         }
//         if(check){ result = max(result, sum); }
//     }
// }

// int main(void){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin >> N >> M;
//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){ cin >> arr[i][j]; }
//     }

//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){ Tetromino(i, j); }
//     }

//     cout << result;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int result = 0;
int Map[501][501];
bool Visit[501][501];
int Move[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<pair<int, int>> st;

int fuckyouCheck(int r, int c) {
	int sum = Map[r][c];
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + Move[i][0];
		int nc = c + Move[i][1];

		if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
			sum += Map[nr][nc];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int nr = r + Move[i][0];
		int nc = c + Move[i][1];

		if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
			ret = max(ret, sum - Map[nr][nc]);
		}
		else ret = max(ret, sum);
	}

	return ret;
}

void dfs(int depth, int r, int c) {
	if (depth > 2) {
		int sum = 0;
		for (int i = 0; i < st.size(); i++)
		{
			sum += Map[st.at(i).first][st.at(i).second];
		}

		result = max(sum, result);
		return;
	}

	result = max(result, fuckyouCheck(r, c));

	for (int i = 0; i < 4; i++)
	{
		int nr = r + Move[i][0];
		int nc = c + Move[i][1];

		if (nr >= 0 && nr < N && nc >= 0 && nc < M && Visit[nr][nc] == false)
		{
			st.push_back(make_pair(nr, nc));
			Visit[nr][nc] = true;
			dfs(depth + 1, nr, nc);
			st.pop_back();
			Visit[nr][nc] = false;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			st.push_back(make_pair(i, j));
			Visit[i][j] = true;
			dfs(0, i, j);
			st.pop_back();
			Visit[i][j] = false;
		}
	}

	cout << result;
}
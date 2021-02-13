// 2048 (Easy)
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 20
using namespace std;
int n, value, value_idx, zero_idx, answer = 2;
int board[MAX][MAX];
int temp[MAX][MAX];
int direction[5]; // 방향 조합 0:상, 1:하, 2:좌, 3:우

void updateCol(int i, int j, queue<int> &zero) {
    // 0의 위치 
	if(board[i][j] == 0){ zero.push(j); }
	else if(board[i][j] != 0 && board[i][j] == value){ // 블럭 값이 같을 때
		value = 0; // 한 번에 한 번만 합치도록 0으로 초기화
		board[i][value_idx] *= 2;
		answer = max(answer, board[i][value_idx]);
		board[i][j] = 0;
		zero.push(j);
	}
	else if(board[i][j] != 0){
		value_idx = j;
		value = board[i][j];
		answer = max(answer, value);
		if (!zero.empty()) {
			zero_idx = zero.front();
			zero.pop();
			board[i][j] = 0;
			board[i][zero_idx] = value;
			zero.push(j);
			value_idx = zero_idx; // 변경
		}
	}
}

void updateRow(int i, int j, queue<int> &zero) {
    // 0의 위치
	if(board[j][i] == 0){ zero.push(j); }
	else if(board[j][i] != 0 && board[j][i] == value){ // 블럭 값이 같을 때
		value = 0; // 한 번에 한 번만 합치도록 0으로 초기화
		board[value_idx][i] *= 2;
		answer = max(answer, board[value_idx][i]);
		board[j][i] = 0;
		zero.push(j);
	}
	else if(board[j][i] != 0){
		value_idx = j;
		value = board[j][i];
		answer = max(answer, value);
		if (!zero.empty()) {
			zero_idx = zero.front();
			zero.pop();
			board[j][i] = 0;
			board[zero_idx][i] = value;
			zero.push(j);
			value_idx = zero_idx; // 변경
		}
	}
}

void moveBlock(int move){
	for(int i=0; i<n; i++){
		queue<int> zero;
		value = 0; value_idx = 0; zero_idx = 0;
		if(move%2 == 0){
			for(int j=0; j<n; j++) {
				if(move == 0){ updateRow(i, j, zero); }
				else { updateCol(i, j, zero); }
			}
		}
		else{
			for(int j=n-1; j>=0; j--){
				if(move == 1){ updateRow(i, j, zero); }
				else{ updateCol(i, j, zero); }
			}
		}
	}
}
void dfs(int idx){
	if(idx == 5){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				board[i][j] = temp[i][j];
			}
		}
		for(int i=0; i<5; i++){
			moveBlock(direction[i]);
		}
		return;
	}
	for(int i=0; i<4; i++) {
		direction[idx] = i;
		dfs(idx+1);
	}
}

int main(){
    scanf("%d", &n);
	for(int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf("%d", &temp[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", answer);
	return 0;
}
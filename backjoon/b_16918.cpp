// 봄버맨
#include <iostream>
#include <string>
using namespace std;
int R, C, N;
string str;
int arr[201][201];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void insertBomb(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(arr[i][j] == 0){ arr[i][j] = 4;}
		}
	}
}

void deleteBomb(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(arr[i][j] > 1){ arr[i][j]--; }
			else if(arr[i][j] == 1){
				arr[i][j] = 0;
				for(int d=0; d<4; d++){
					int x = i + dx[d];
					int y = j + dy[d];
					if(x < 0 || y < 0 || x >= R || y >= C){ continue; }
					if((d == 0 || d == 1) && arr[x][y] == 1){ continue; }
					arr[x][y] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> R >> C >> N;
	N--;
	for(int i=0; i<R; i++){
		cin >> str;
		for(int j=0; j<C; j++){
			if(str[j] == 'O'){ arr[i][j] = 2; }
		}
	}
	
	while(N--){
		insertBomb();
		deleteBomb();
	}
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(arr[i][j] >= 1){ cout << "O"; }
			else{ cout << "."; }
		}
		cout << "\n";
	}
	return 0;
}
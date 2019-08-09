#include <iostream>
using namespace std;
int N, M;
int arr[9];

void DFS(int c){
    if (c == M){
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return; 
	}
	for (int i = 1; i <= N; i++){
		if (arr[c-1] <= i){
			arr[c] = i;
			DFS(c + 1);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    DFS(0);
    return 0;
}
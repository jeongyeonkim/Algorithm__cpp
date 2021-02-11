#include <iostream>
#include <vector>
using namespace std;
int N, M;
int visit[9];
int arr[9];

void Function(int c){
    if (c == M){
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return; 
	}
	for (int i = 1; i <= N; i++){
		if (!visit[i]){
			visit[i] = 1;
			arr[c] = i;
			Function(c + 1);
			visit[i] = 0;
		}
	}
}

int main(){
    cin >> N >> M;
    Function(0);
    return 0;
}
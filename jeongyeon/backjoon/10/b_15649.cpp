#include <iostream>
#include <vector>
using namespace std;
int N, M;
int visit[9];
int arr[9];

void function(int c){
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
			function(c + 1);
			visit[i] = 0;
		}
	}
}

int main(){
    cin >> N >> M;
    function(0);
    return 0;
}
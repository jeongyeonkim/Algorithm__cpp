// 이모티콘
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
int S;
int emoticon[1001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> S;
	for(int i=2; i<=1000; i++){ emoticon[i] = INF; }
	emoticon[0] = 1;
	emoticon[1] = 0;
	for(int i=1; i<=1000; i++){
		emoticon[i-1] = min(emoticon[i-1], emoticon[i] + 1);
		for(int j=2; j*i<=1000; j++){
			emoticon[i * j] = min(emoticon[i * j], emoticon[i] + j);
			emoticon[(i * j) - 1] = min(emoticon[(i * j) - 1], emoticon[i] + j + 1);
		}
	}
	
	cout << emoticon[S];
	return 0;
}
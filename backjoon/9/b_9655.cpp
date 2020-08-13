// 돌 게임
// 홀수가 들어오면 상근이가 이김
// 한번에 1 or 3개의 돌을 가져갈 수 있기 때문.
#include <iostream>
using namespace std;
int N;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	if(N%2 == 0){
		cout << "CY";
	}else{
		cout << "SK";
	}
	return 0;
}
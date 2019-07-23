#include <cstdio>
#include <stack>
#include <vector>
#define MAX 1000001
using namespace std;
stack<int> a, ans, num;
int main() {
	int n, input;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &input);
		num.push(input);
	}
	a.push(MAX);
	while(!num.empty()) {
		while(a.top() <= num.top()) a.pop(); // 같을 때도 pop을 해주어야 다음 큰 값을 비교가능
		if(a.top() == MAX) ans.push(-1);
		else ans.push(a.top());
		a.push(num.top()); num.pop();
	}
	while(!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}
// 카드 정렬하기
// 최소 힙을 사용하여 최솟값 계속 갱신
// 최소 2개끼리 비교하는게 최소 비교이다
#include <iostream>
#include <queue>
using namespace std;
int N, input;
priority_queue<long long> que;
long long n1, n2, temp, result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> input;
        que.push((-1)*input);
    }
    if(N == 1){ // N = 1일때는 비교할게 없어서 0으로 출력!
        cout << 0;
        return 0;
    }
    while (que.size() >= 2){
        n1 = que.top();
        que.pop();
        n2 = que.top();
        que.pop();

        temp = n1 + n2;
        result += (-1)*temp;
        que.push(temp);
    }

    cout << result;
    return 0;
}
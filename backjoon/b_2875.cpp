//대회 or 인턴
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, result;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;

    //N/2 : 여자로 만들 수 있는 최대 팀 수.
    //N/2 와 M 중에 작은 수로 팀의 갯수로 설정하고 남은 큰 수에서 K를 뺌.
    //N+M-K : 총 인원수에서 3을 나누면 여자2, 남자1로 이루어진 팀의 수.
    result = min(N/2, M);
    result = min( result, ( N + M - K )/3 );

    cout << result;
}
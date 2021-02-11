// 날짜 계산
// 1. 브루트포스
// 2. (우리가 알고 있는 연도) % (지구, 태양, 달의 각각의 최대 수) == (지구, 태양, 달 각 수)
// 3. 지구, 태양, 달 모두가 2번에 만족할 경우 답
#include <iostream>
using namespace std;
long long result;
int E, S, M;

bool dayCheck(int n, int day){
    if(result % n == day){ return true; }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> E >> S >> M;
    if(E == 15){ E = 0; }
    if(S == 28){ S = 0; }
    if(M == 19){ M = 0; }
    while (true){
        result++;
        if(!dayCheck(15, E) || !dayCheck(28, S) || !dayCheck(19, M)){ continue; }
        else{ break; }
    }
    
    cout << result;
    return 0;
}
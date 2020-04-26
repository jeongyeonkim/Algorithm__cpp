//초콜릿 자르기
#include <iostream>
using namespace std;
int N, M, result, Max, Min;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;

    if(N > M){
        Max = N; Min = M;
    }else{
        Max = M; Min = N;
    }

    result += Max -1;
    result += (Min-1)*Max;

    cout << result;
}
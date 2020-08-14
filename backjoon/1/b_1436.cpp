// 영화감독 숌
// 숫자를 1개씩 올리면서
// 숫자를 문자 변환 후
// 해당 문자열에 666 포함 여부에 따라 cnt
// cnt == N일 경우 해당 숫자 출력
#include <iostream>
#include <string>
using namespace std;
int N, cnt;
long long num = 665;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    while (cnt < N){
        num++;
        if(to_string(num).find("666") != string::npos){
            cnt++;

        }
    }
    
    if(N == 0){ cout << 0; }
    else{ cout << num; }
    return 0;
}
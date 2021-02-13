// 피보나치 수의 확장
// + / - 는 대칭관계
// -일 경우 짝수일 때 음수 붙음
#include <iostream>
#include <cstdlib>
#define divide 1000000000
#define num 1000000
using namespace std;
int n;
int fibo[2000002];

void result(int res){
    if(res < 0){
        cout << -1 << "\n";
    }
    else if(res > 0){
        cout << 1 << "\n";
    }
    else{ cout << 0 << "\n"; }

    cout << abs(res);
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    fibo[1] = 1;
    fibo[num+1] = 1;
    if(n >= 2){
        for(int i=2; i<=n; i++){
            fibo[i] = (fibo[i-1] + fibo[i-2]) % divide;
        }

        result(fibo[n]);
    }

    else if(n < 0){
        for(int i=-1; i>=n; i--){
            fibo[i+num] = (fibo[i+2+num] - fibo[i+1+num]) % divide;
        }

        result(fibo[n+num]);
    }

    else if(n == 1){ result(1); }
    else{ result(0); }

    return 0;
}
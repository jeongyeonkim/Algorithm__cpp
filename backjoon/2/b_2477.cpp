// 숫자의 개수
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int multi = 1, len;
int num[10];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a = 0;
    // multi에 곱셈 값 저장
    cin >> a; multi *= a;
    cin >> a; multi *= a;
    cin >> a; multi *= a;

    // i = 자릿 수
    for(int i=to_string(multi).length()-1; i>=0; i--){
        num[multi/(int)pow(10,i)]++;
        multi %= (int)pow(10, i);
    }

    for(int i=0; i<=9; i++){ cout << num[i] << "\n"; }
}
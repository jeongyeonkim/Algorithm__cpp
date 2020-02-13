// 수 이어 쓰기 1
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
string N;
int len;
long long result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    len = N.length();

    for(int i=len-1; i>0; i--){
        result += 9*(long long)pow(10, len-1-i)*(len-i);
    }
    
    result += (len * (stoi(N) - (long long)pow(10, len-1) + 1));

    cout << result;
}
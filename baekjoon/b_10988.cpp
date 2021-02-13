// 팰린드롬인지 확인하기
#include <iostream>
#include <string>
using namespace std;
string str;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    int len = str.length();
    for(int i=0; i<len/2; i++){
        if(str[i] != str[len-i-1]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
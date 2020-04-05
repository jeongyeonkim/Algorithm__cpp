// 알파벳 개수
#include <iostream>
#include <string.h>
using namespace std;
string str;
int num[26];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        num[str[i]-'a']++;
    }

    for(int i=0; i<26; i++){ cout << num[i] << " "; }
    return 0;
}
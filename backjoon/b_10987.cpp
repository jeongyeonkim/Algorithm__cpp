// 모음의 개수
#include <iostream>
#include <string>
using namespace std;
string str;
int cnt;
char arr[5] = {'a', 'e', 'o', 'i', 'u'};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        for(int j=0; j<5; j++){
            if(arr[j] == str[i]){ cnt++; break; }
        }
    }

    cout << cnt;
    return 0;
}
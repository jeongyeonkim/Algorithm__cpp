// 단어 공부
#include <iostream>
#include <string.h>
using namespace std;
char result = -1;
string arr;
int frequency[58], sum;
bool check;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> arr;

    for(int i=0; i<arr.length(); i++){ frequency[arr[i]-65]++; }

    // A = 65, a = 97, Z = 90, z = 122
    for(int i=0; i<=25; i++){
        if(sum <= frequency[i] + frequency[i+32]){
            // 많이 사용하는 알파벳이 여러개 존재할 경우
            if(sum == frequency[i] + frequency[i+32]){ check = true; }
            else{
                check = false;
                sum = frequency[i] + frequency[i+32];
                result = i + 65;
            }
        }
    }
    if(check){ cout << "?"; }
    else{ cout << result; }

    return 0;
}
// 카이사르 암호
#include <iostream>
#include <string>
using namespace std;
string str, result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'A'){ result += "X"; }
        else if(str[i] == 'B'){ result += "Y"; }
        else if(str[i] == 'C'){ result += "Z"; }
        else{ result += str[i] - 3; }
    }

    cout << result;
    return 0;
}
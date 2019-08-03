#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;    cin >> str;
    for(int i=0; i<str.length(); i++)
        str[i]=toupper(str[i]);
    
    cout << str;
    return 0;
}
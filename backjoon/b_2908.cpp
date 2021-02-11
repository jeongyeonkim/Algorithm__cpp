// 상수
#include <iostream>
#include <string.h>
using namespace std;
string temp1, temp2;
int num1, num2;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a;
    getline(cin, a);
    bool check = true;
    for(int i=a.length()-1; i>=0; i--){
        if(a[i] == ' '){ check = false; continue; }
        if(check){ temp1 += a[i]; }
        else{ temp2 += a[i]; }
    }
    
    num1 = atoi(temp2.c_str()), num2 = atoi(temp1.c_str());

    if(num1 > num2){ cout << num1; }
    else{ cout << num2; }
}
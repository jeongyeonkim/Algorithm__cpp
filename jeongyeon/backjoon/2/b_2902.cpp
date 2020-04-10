// KMP는 왜 KMP일까?
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string str, result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    istringstream ss(str);
    string temp;
    while(getline(ss, temp, '-')){
        result += temp[0];
    }

    cout << result;
    return 0;
}
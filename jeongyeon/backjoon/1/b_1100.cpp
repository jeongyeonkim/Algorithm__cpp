// 하얀 칸
#include <iostream>
#include <string>
using namespace std;
string str;
int idx, result;

int main(void){
    for(int i=0; i<8; i++){
        cin >> str;
        if(i%2 == 1){ idx = 1; }
        else{ idx = 0; }
        
        for(int j=idx; j<str.length(); j+=2){
            if(str[j] == 'F'){ result++; }
        }
    }

    cout << result;
    return 0;
}
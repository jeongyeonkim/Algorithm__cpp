// 유학금지
#include <iostream>
#include <string>
using namespace std;
string str, result;
char arr[9] = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'};

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        bool check = true;
        for(int j=0; j<9; j++){
            if(str[i] == arr[j]){
                check = false;
                break;
            }
        }

        if(check){ result += str[i]; }
    }

    cout << result;
    return 0;
}
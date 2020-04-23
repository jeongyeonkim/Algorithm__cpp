//JOI와 IOI
#include <iostream>
#include <string>
using namespace std;
char ch1[3] = {'J', 'O', 'I'};
char ch2[3] = {'I', 'O', 'I'};
int result1, result2;
string str;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length()-2; i++){
        if(str[i] == ch1[0] && str[i+1] == ch1[1] && str[i+2] == ch1[2]){
            result1++;
        }else if(str[i] == ch2[0] && str[i+1] == ch2[1] && str[i+2] == ch2[2]){
            result2++;
        }
    }
    cout << result1 << "\n" << result2;
}
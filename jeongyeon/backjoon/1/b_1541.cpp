//잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;
string input, num;
int output;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> input;
    bool minus = false;

    for(int i=0; i<=input.length(); i++){
        num += input[i];
        //부호가 나오면 앞에 저장된 값을 더하거나 빼거나 함.
        // \0 : null 값인 경우 맨 마지막 숫자를 처리하기 위함. ( 그래서 for문을 i<=input.length() 까지 처리함. )
        if(input[i] == '-' || input[i] == '+' || input[i] == '\0'){
            if(!minus){
                output += stoi(num);
            }else{
                output -= stoi(num);
            }
            num = "";

            if(input[i] == '-'){ minus = true; }
        }
    }

    cout << output;
}
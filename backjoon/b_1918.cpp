// 후위 표기식
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string str, result;
stack<char> arr;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){ result += str[i]; }
        else if(str[i] == '('){ arr.push(str[i]); }
        else{
            if(str[i] == ')'){
                while (!arr.empty() && arr.top() != '('){
                    result += arr.top();
                    arr.pop();
                }
                arr.pop();
            }
            else if(str[i] == '*' || str[i] == '/'){
                while (!arr.empty() && (arr.top() == '*' || arr.top() == '/')) {
                    result += arr.top();
                    arr.pop();
                }
                arr.push(str[i]);
            }
            else if(str[i] == '+' || str[i] == '-'){
                while (!arr.empty() && arr.top() != '('){
                    result += arr.top();
                    arr.pop();
                }
                arr.push(str[i]);
            }
        }
    }

    while (!arr.empty()){
        result += arr.top();
        arr.pop();
    }
    
    cout << result;
    return 0;
}
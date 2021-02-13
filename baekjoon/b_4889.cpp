// 안정적인 문자열
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
int result, test_case;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> str){
        if(str[0] == '-'){ break; }
        test_case++;
        result = 0;
        stack<char> arr;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '{'){ arr.push(str[i]); }
            else{
                if(arr.empty()){
                    arr.push('{');
                    result++;
                }
                else{ arr.pop(); }
            }
        }
        
        result += arr.size() / 2;
        if(arr.size() % 2 != 0){ result++; }
        
        cout << test_case << ". " << result << "\n";
    }
    return 0;
}
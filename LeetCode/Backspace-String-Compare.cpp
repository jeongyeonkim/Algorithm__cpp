#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 0ms 6.4KB
// 1. string 내 # 나오면 이전 문자 지움
// 2. S, T 모두 1 진행 후 값 비교
string findWord(string str){
    string result = "";

    for(int i=0; i<str.length(); i++){
        if(str[i] == '#' && result.compare("")){
            result = result.substr(0, result.length() - 1);
        } else if(str[i] != '#'){
            result += str[i];
        }
    }

    return result;
}

bool backspaceCompare(string S, string T) {

    return (findWord(S).compare(findWord(T)) == 0);
}

int main(){
    string s = "ab##";
    string t = "c#d#";
    cout << backspaceCompare(s, t);
}